#pragma once
#include "elf.h"
#include "memory.h"

#include <fstream>
#include <vector>
#include <cstdio>

namespace rpcs4
{
	namespace elf
	{
		void load_from_memory(const void *data)
		{
			const char *raw = (const char *)data;
			ehdr& elf_header = *(ehdr *)raw;

			std::printf("elf header:\n");
			std::printf("    magic        0x%08x\n", elf_header.magic);
			std::printf("    eclass       0x%02x\n", elf_header.eclass);
			std::printf("    data         0x%02x\n", elf_header.data);
			std::printf("    curver       0x%02x\n", elf_header.curver);
			std::printf("    os_abi       0x%02x\n", elf_header.os_abi);
			std::printf("    abi_ver      0x%02x\n", elf_header.abi_ver);
			std::printf("    type         0x%04x\n", elf_header.type);
			std::printf("    machine      0x%04x\n", elf_header.machine);
			std::printf("    version      0x%08x\n", elf_header.version);
			std::printf("    entry        0x%016llx\n", elf_header.entry);
			std::printf("    phoff        0x%016llx\n", elf_header.phoff);
			std::printf("    shoff        0x%016llx\n", elf_header.shoff);
			std::printf("    flags        0x%08x\n", elf_header.flags);
			std::printf("    ehsize       %u\n", elf_header.ehsize);
			std::printf("    phentsize    %u\n", elf_header.phentsize);
			std::printf("    phnum        %u\n", elf_header.phnum);
			std::printf("    shentsize    %u\n", elf_header.shentsize);
			std::printf("    shnum        %u\n", elf_header.shnum);
			std::printf("    shstrndx     %u\n", elf_header.shstrndx);

			std::printf("\nprogram headers:\n");
			std::printf("    #    type         flags        offset               vaddr                paddr                 memsz                align\n");

			phdr* program_headers = (phdr *)(raw + elf_header.phoff);
			for (std::uint16_t i = 0; i < elf_header.phnum; ++i)
			{
				std::printf("    %-3u  0x%08x   0x%08x   0x%016llx   0x%016llx   0x%016llx    0x%016llx   0x%016llx\n",
					i,
					program_headers[i].type,
					program_headers[i].flags,
					program_headers[i].offset,
					program_headers[i].vaddr,
					program_headers[i].paddr,
					program_headers[i].memsz,
					program_headers[i].align
				);

				memory::copy(program_headers[i].vaddr, raw + program_headers[i].offset, program_headers[i].memsz);
			}
		}

		void load_from_file(const std::string &path)
		{
			std::vector<char> file_data;

			{
				std::ifstream file(path, std::ios::binary | std::ios::ate);
				file_data.resize(file.tellg().seekpos());
				file.seekg(0, file.beg);
				file.read(file_data.data(), file_data.size());
			}

			load_from_memory(file_data.data());
		}
	}
}
