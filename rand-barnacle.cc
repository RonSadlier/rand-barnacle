/* -*- c++ -*- */
/*
 * Copyright 2015 Ronald Sadlier - Oak Ridge National Laboratory
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <fstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/program_options.hpp"
#include "boost/random.hpp"

/**
 * The main entry point.
 */
int main(int argc, char *argv[]) {
	std::uint_fast64_t seed(0);
	std::string outputFile;
	std::uint_fast64_t count(0);
	
	try {
		namespace po = boost::program_options;
		
		po::options_description desc("Options");
		desc.add_options()
				("help,h", "Print help")
				("seed,s", po::value<unsigned long>(&seed), "Seed Value")
				("output,o", po::value<std::string>(&outputFile)->required(), "Output File")
				("count,c", po::value<unsigned long>(&count), "Output Byte Count");
		
		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		
		if(vm.count("help")) {
			std::cout << "rand-barnacle" << std::endl << desc << std::endl;
			exit(0);
		}
		
		po::notify(vm);
	} catch(boost::program_options::required_option &e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	} catch(boost::program_options::error &e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
	
	// If no seed is supplied, we use the system time with high precision.
	if(seed == 0) {
		// The actual implementation of microsec_clock is a bit platform
		// specific. On Windows this has millisecond resolution whereas on Unix
		// we can normally achieve higher resolution.
		boost::posix_time::time_duration td(boost::posix_time::microsec_clock::universal_time().time_of_day());
		seed = td.total_microseconds();
		std::cout << "Seed: " << seed << std::endl;
	}
	
	std::ofstream output(outputFile, std::ios::binary);
	if(!output.is_open()) {
		std::cerr << "Could not open binary file for writing" << std::endl;
		exit(-1);
	}
	
	if(count <= 0) {
		std::cerr << "Zero output size" << std::endl;
		exit(-1);
	}
	
	boost::mt19937 rng;
	rng.seed(seed);
	boost::random::uniform_int_distribution<> byte(0,255);
	char* outBuffer = new char[count];
	
	for(std::size_t i = 0; i < count; i++) {
		outBuffer[i] = byte(rng);
	}
	
	output.write(outBuffer, count);
	delete[] outBuffer;
	output.close();
	
	std::cout << "Wrote " << count << " bytes to " << outputFile << std::endl;
}
