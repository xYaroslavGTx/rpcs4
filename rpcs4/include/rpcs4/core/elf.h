#pragma once
#include <cstdint>
#include <string>

namespace rpcs4
{
	namespace elf
	{
		struct ehdr
		{
			std::uint32_t magic;
			std::uint8_t eclass;
			std::uint8_t data;
			std::uint8_t curver;
			std::uint8_t os_abi;
			std::uint8_t abi_ver;
			std::uint8_t pad[7];
			std::uint16_t type;
			std::uint16_t machine;
			std::uint32_t version;
			std::uint64_t entry;
			std::uint64_t phoff;
			std::uint64_t shoff;
			std::uint32_t flags;
			std::uint16_t ehsize;
			std::uint16_t phentsize;
			std::uint16_t phnum;
			std::uint16_t shentsize;
			std::uint16_t shnum;
			std::uint16_t shstrndx;
		};

		struct phdr
		{
			std::uint32_t type;
			std::uint32_t flags;
			std::uint64_t offset;
			std::uint64_t vaddr;
			std::uint64_t paddr;
			std::uint64_t filesz;
			std::uint64_t memsz;
			std::uint64_t align;
		};

		struct shdr
		{
			std::uint32_t name;
			std::uint32_t type;
			std::uint64_t flags;
			std::uint64_t addr;
			std::uint64_t offset;
			std::uint64_t size;
			std::uint32_t link;
			std::uint32_t info;
			std::uint64_t addralign;
			std::uint64_t entsize;
		};

		void load_from_memory(const void *data);
		void load_from_file(const std::string &path);
	}
}
