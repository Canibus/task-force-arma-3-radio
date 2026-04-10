#include "script_component.hpp"

/*
  Name: TFAR_fnc_onSwVolumeChange

  Author: Poison
    change the volume of the sw radio.

  Arguments:
    0: Key number (0 - decr, 1 - incr) <NUMBER>

  Return Value:
    Whether or not the event was handled <BOOL>

  Example:
    // SW radio
    [_this select 1] call TFAR_fnc_onSwVolumeChange;

  Public: Yes
*/

params ["_btn"];

private _result = false;

if ((alive TFAR_currentUnit) and {call TFAR_fnc_haveSWRadio}) then {
    private _radio = call TFAR_fnc_activeSwRadio;

    private _maxVolume = TF_MAX_SW_VOLUME;
	  private _fnc_GetVolume = TFAR_fnc_getSwVolume;

    private _vChange = if(_btn == 0)then{-1 + _maxVolume}else {1};
	  _vChange = ((_radio call _fnc_GetVolume) + _vChange) mod _maxVolume;

    [_radio, _vChange] call TFAR_fnc_setSwVolume;

    playSound "TFAR_rotatorPush";

	  [_radio] call TFAR_fnc_showRadioVolume;

	  _result = true;
};
_result
