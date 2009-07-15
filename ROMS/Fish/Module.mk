# svn $Id: Module.mk 975 2009-05-05 22:51:13Z kate $
#::::::::::::::::::::::::::::::::::::::::::::::::::::: Hernan G. Arango :::
# Copyright (c) 2002-2009 The ROMS/TOMS Group             Kate Hedstrom :::
#   Licensed under a MIT/X style license                                :::
#   See License_ROMS.txt                                                :::
#::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

local_sub  := ROMS/Fish

local_lib  := libFish.a
local_src  := $(wildcard $(local_sub)/*.F)
local_src  += $(wildcard $(local_sub)/*.cc)

$(eval $(call make-library,$(local_lib),$(local_src)))

$(eval $(compile-rules))
