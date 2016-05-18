#pragma once
#include <cstdint>
#include <cstddef>

namespace rpcs4
{
	namespace memory
	{
		extern void *g_base;

		using address_t = std::uint64_t;

		void initialize();
		void destroy();

		template<typename T = void>
		inline T* get(address_t address = 0)
		{
			return (T*)((const char *)g_base + address);
		}

		void copy(address_t dest_address, const void *source, std::size_t size);
	}
}
