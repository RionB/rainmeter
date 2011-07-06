/*
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __LUAMANAGER_H__
#define __LUAMANAGER_H__

#include "lua.hpp"
#include "tolua++.h"
#include "LuaPush.h"

class LuaManager
{
public:
	static void Init();
	static void CleanUp();

	static lua_State* GetState() { return c_State; }

	static void ReportErrors(lua_State* L);
	static void LuaLog(int nLevel, const char* format, ... );

protected:
	static int c_RefCount;
	static lua_State* c_State;

private:
	static void RegisterGlobal(lua_State* L);
	static void RegisterRainmeter(lua_State* L);
	static void RegisterGroup(lua_State* L);
	static void RegisterMeasure(lua_State* L);
	static void RegisterMeter(lua_State* L);
	static void RegisterMeterWindow(lua_State* L);
	static void RegisterMeterString(lua_State* L);
};

#endif
