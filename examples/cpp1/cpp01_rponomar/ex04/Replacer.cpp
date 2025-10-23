/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:08:44 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 22:34:39 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <sys/stat.h>
#include <errno.h>


rpl::Replacer::Replacer(const std::string& prog, const std::string& name, const std::string& target, const std::string& replacement)
{
	if (name.empty() || target.empty())
	{
		std::cerr << '\t' << prog << ": Error: File_name or Target_str is empty\n";
		std::exit(EXIT_FAILURE);
	}
	prog_ = "\t" + prog + ": ";
	src_name_ = name;
	dst_name_ = name + ".replace";
	target_ = target;
	replacement_ = replacement;
}

void	rpl::Replacer::replace(void)
{

	struct stat file_info;
	if (stat(src_name_.c_str(), &file_info))
		throw std::runtime_error(prog_ + "Error: Can't access sourse file: " + src_name_); 
	else if (file_info.st_mode & S_IFDIR)
		throw std::runtime_error(prog_ + "Error: Sourse file is a directory: " + src_name_);
	else if (!(file_info.st_mode & S_IFREG))
		throw std::runtime_error(prog_ + "Error: Sourse file isn't a regular file: " + src_name_);
	else if (file_info.st_size > MAX_SUPPORTED_FILE_SIZE)
		throw std::runtime_error(prog_ + "Error: Sourse file is too big: " + src_name_);

	std::ifstream ifs(src_name_.c_str());
		if (!ifs.is_open())
			throw std::runtime_error(prog_ + "Error: Fail to open source file: " + src_name_);		

	std::ofstream ofs(dst_name_.c_str());
	if (!ofs.is_open())
		throw std::runtime_error(prog_ + "Error: Fail to open destination file: " + dst_name_);

	std::stringstream ss;
	ss << ifs.rdbuf();
	if (!ifs.good())
		throw std::runtime_error(prog_ + "Error: Fail to read source file: " + src_name_);
	buff_ = ss.str();

	if (buff_.empty())
	{
		std::cerr << prog_ << "Warning: Source file is empty"; 
		return ;
	}

	std::string::size_type start = 0;
	std::string::size_type pos_target = buff_.find(target_);
	std::string::size_type len_remaining = pos_target - start;
	std::string::size_type len_target = target_.length();
	
	while (pos_target != std::string::npos)	
	{
		ofs << buff_.substr(start, len_remaining) << replacement_;
		start = pos_target + len_target;
		pos_target = buff_.find(target_, start);
		len_remaining = pos_target - start;
	}

	ofs << buff_.substr(start, std::string::npos);
}

