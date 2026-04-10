#include "script_component.hpp"

/*
  Name: TFAR_fnc_onLRVolumeChange

  Author: Poison
    change the volume of the lr radio.

  Arguments:
    0: Key number (0 - decr, 1 - incr) <NUMBER>

  Return Value:
    Whether or not the event was handled <BOOL>

  Example:
    // SW radio
    [_this select 1] call TFAR_fnc_onLRVolumeChange;

  Public: Yes
*/

params ["_btn"];

private _result = false;

if ((alive TFAR_currentUnit) and {call TFAR_fnc_haveLRRadio}) then {
    private _radio = call TFAR_fnc_activeLrRadio;

    private _maxVolume = TF_MAX_LR_VOLUME;
	  private _fnc_GetVolume = TFAR_fnc_getLrVolume;

    private _vChange = if(_btn == 0)then{-1 + _maxVolume}else {1};
	  _vChange = ((_radio call _fnc_GetVolume) + _vChange) mod _maxVolume;

    [_radio, _vChange] call TFAR_fnc_setLrVolume;

    playSound "TFAR_rotatorPush";

	  [_radio] call TFAR_fnc_showRadioVolume;

	  _result = true;
};
_result
