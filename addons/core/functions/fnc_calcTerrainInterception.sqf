#include "script_component.hpp"

/*
  Name: TFAR_fnc_calcTerrainInterception

  Author: NKey
    Calculates the terrain interception between the player and the passed unit.

  Arguments:
    0: Unit to calculate terrain interception with. <OBJECT>

  Return Value:
    Terrain Interception <SCALAR>

  Example:
    _interception = soldier2 call TFAR_fnc_calcTerrainInterception;

  Public: No
*/

#define STEP 5
private _result = 0;
private _p1 = eyePos TFAR_currentUnit;
private _p2 = eyePos _this;
private _lowHeight = false;

private _intersects = terrainIntersectASL [_p1, _p2];
private _i = 0;
while {_intersects && _i < 3} do {
    _p1 set [2, _p1#2 + STEP];
    _p2 set [2, _p2#2 + STEP];
    _i = _i + 1;
    _result = _result + STEP;
    private _pp1 = terrainIntersectAtASL [_p1, _p2];
    private _pp2 = terrainIntersectAtASL [_p2, _p1];
    _intersects = _pp1 isNotEqualTo _pp2;
    if (_intersects) then {
        _p1 = _pp1;
        _p2 = _pp2;
    } else {
        _lowHeight = true;
    };
};

if (!_lowHeight) then {
    _p1 = eyePos TFAR_currentUnit;
    _p2 = eyePos _this;
};

if (terrainIntersectASL[_p1, _p2]) then {
    private _l = 10.0;
    private _r = 250.0;
    private _m = 100.0;

    private _middle = (_p1 vectorAdd _p2) vectorMultiply 0.5;
    private _base = _middle select 2;

    while {(_r - _l) > 10} do {
        _middle set[2, _base + _m];
        if ((!terrainIntersectASL [ _p1, _middle ]) and {!terrainIntersectASL [ _p2, _middle ]}) then {
            _r = _m;
        } else {
            _l = _m;
        };
        _m = (_l + _r) / 2.0;
    };
    if (_lowHeight) then {
        _middle set[2, _base + _m];
        private _pointToLineDist = sqrt (vectorMagnitudeSqr ( (_middle vectordiff _p1) vectorCrossProduct (_middle vectordiff _p2) ) / vectorMagnitudeSqr (_p2 vectordiff _p1));
        _result = _result + _pointToLineDist;
    } else {
        _result = _m;
    };
};
_result
