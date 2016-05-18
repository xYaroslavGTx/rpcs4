#include <rpcs4/core/elf.h>
#include <rpcs4/core/memory.h>

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		rpcs4::memory::initialize();
		rpcs4::elf::load_from_file(argv[i]);
		rpcs4::memory::destroy();
	}

	return 0;
}
