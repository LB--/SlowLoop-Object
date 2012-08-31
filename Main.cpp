// ============================================================================
//
// This file contains the actions, conditions and expressions your object uses
// 
// ============================================================================

#include "Common.h"
#include "ParamHelp.h"

// ============================================================================
//
// CONDITIONS
// 
// ============================================================================

CONDITION(
	/* ID */			0,
	/* Name */			"SlowLoop %0 up to %1 times",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_STRING,"SlowLoop Name",PARAM_NUMBER,"Repeat Times")
) {
	string ID = StrParam();
	if((*rdPtr->SlowLoops)[ID].Index < (unsigned)lParam())
	{
		(*rdPtr->SlowLoops)[ID].Trigger = true;
		return true;
	}
	return false;
}

// ============================================================================
//
// ACTIONS
// 
// ============================================================================

ACTION(
	/* ID */			0,
	/* Name */			"Set Slow Loop Index of %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"SlowLoop Name",PARAM_NUMBER,"Index")
) {
	(*rdPtr->SlowLoops)[StrParam()].Index = (unsigned)lParam();
}

// ============================================================================
//
// EXPRESSIONS
// 
// ============================================================================

EXPRESSION(
	/* ID */			0,
	/* Name */			"SlowLoopIndex(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_STRING,"SlowLoop Name")
) {
	return (*rdPtr->SlowLoops)[EStrParam()].Index;
}