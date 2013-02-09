#ifndef PAWN_H
#define PAWN_H

#ifdef __WIN32__
#include <winsock2.h>
#endif
#include <cstdio>
#include <cstdlib>
#include <map>

#define HAVE_STDINT_H
#include "amx/amx.h"
#include "amx/amxaux.h"

#include "boost/any.hpp"

#include "../Utils.h"
#include "../VaultException.h"
#include "../vaultmp.h"

/**
 * \brief Contains the PAWN scripting function wrappers
 */

class PAWN
{
	private:
		PAWN() = delete;

		static AMX_NATIVE_INFO functions[110];

		static cell CreateTimer(AMX* amx, const cell* params);
		static cell CreateTimerEx(AMX* amx, const cell* params);
		static cell MakePublic(AMX* amx, const cell* params);
		static cell CallPublic(AMX* amx, const cell* params);

	public:
		static int LoadProgram(AMX* amx, char* filename, void* memblock);
		static int Register(AMX* amx, const AMX_NATIVE_INFO* list, int number);
		static int Exec(AMX* amx, cell* retval, int index);
		static int FreeProgram(AMX* amx);
		static bool IsCallbackPresent(AMX* amx, const char* name);
		static cell Call(AMX* amx, const char* name, const char* argl, int buf, ...);
		static cell Call(AMX* amx, const char* name, const char* argl, const std::vector<boost::any>& args);

		static int CoreInit(AMX* amx);
		static int ConsoleInit(AMX* amx);
		static int FloatInit(AMX* amx);
		static int TimeInit(AMX* amx);
		static int StringInit(AMX* amx);
		static int FileInit(AMX* amx);

		static int RegisterVaultmpFunctions(AMX* amx);
};

#endif
