#pragma once
#include "memory.h"
#include <cstring>

namespace rpcs4
{
	namespace memory
	{
		//TODO

		void *g_base = nullptr;

		void initialize()
		{
			g_base = new int[0x7fff'ffff];
		}

		void destroy()
		{
			delete[] (int *)g_base;
		}

		void copy(address_t dest_address, const void *source, std::size_t size)
		{
			std::memcpy(get(dest_address), source, size);
		}
	}
}
