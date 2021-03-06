#pragma once

#include "FileData.h"

#include <fstream>
#include <memory>
#include <map>

namespace only2d
{
	enum class FileMode
	{
		READ,
		WRITE,
		APPEND,
		BINARY_READ,
		BINARY_WRITE,
		BINARY_APPEND
	};

	enum class FileReadMode : int32_t
	{
		MinInvalid,
		BLOCK,
		ALL,
		MaxInvalid
	};

	class File
	{
	public:
		File(const std::string &filename, FileMode mode);

		virtual ~File();

		bool good();

		size_t getSize();

		std::shared_ptr<FileData> read(FileReadMode readMode, size_t size = 0);

		bool read(std::string &line);

		bool write(std::shared_ptr<Data> data);

		bool write(const std::string &line);

		bool flush();

		bool eof();

		size_t tell();

		size_t available();

		bool seek(size_t pos);

	private:
		bool isRead();

		bool isBinary();

	private:
		std::string filename;
		FileMode mode;
		std::fstream handle;
	};
}