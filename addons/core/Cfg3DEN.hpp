/*
class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class Attributes {
                    items[] += {"TFAR_Preferences"};
                };
                class TFAR_Preferences {
                    text = ECSTRING(core,3DEN_Menu);
                    action = "edit3DENMissionAttributes 'TFAR_Preferences';";
                    picture = QPATHTOF(task_force_arrowhead_logo.paa);
                };
            };
        };
    };
};
*/

#define SWCode  if (_value isEqualTo '' || _value isEqualTo []) exitWith {};\
                if (_value isEqualType '') then {\
                    _value = [ARR_5(_value,TFAR_MAX_CHANNELS,TFAR_MAX_SW_FREQ,TFAR_MIN_SW_FREQ,TFAR_FREQ_ROUND_POWER)] call DFUNC(parseFrequenciesInput);\
                    _this setVariable [ARR_3('%s',_value,true)];\
                } else {\
                    _value = [ARR_5(str _value,TFAR_MAX_CHANNELS,TFAR_MAX_SW_FREQ,TFAR_MIN_SW_FREQ,TFAR_FREQ_ROUND_POWER)] call DFUNC(parseFrequenciesInput);\
                    _this setVariable [ARR_3('%s',_value,true)];\
                }
#define LRCode  if (_value isEqualTo '' || _value isEqualTo []) exitWith {};\
                if (_value isEqualType '') then {\
                    _value = [ARR_5(_value,TFAR_MAX_LR_CHANNELS,TFAR_MAX_ASIP_FREQ,TFAR_MIN_ASIP_FREQ,TFAR_FREQ_ROUND_POWER)] call DFUNC(parseFrequenciesInput);\
                    _this setVariable [ARR_3('%s',_value,true)];\
                } else {\
                    _value = [ARR_5(str _value,TFAR_MAX_LR_CHANNELS,TFAR_MAX_ASIP_FREQ,TFAR_MIN_ASIP_FREQ,TFAR_FREQ_ROUND_POWER)] call DFUNC(parseFrequenciesInput);\
                    _this setVariable [ARR_3('%s',_value,true)];\
                }

class Cfg3DEN {
    /*
    class Mission {
        class TFAR_Preferences {
            displayName = ECSTRING(core,3DEN_Menu);
            class AttributeCategories {
                
            };
        };
    };
    */
    class Object {
        class AttributeCategories {
            class TFAR_attributes {
                displayName = ECSTRING(core,3DEN_Properties);
                collapsed = 1;
                class Attributes {
                    class TFAR_freq_sr {
                        displayName = ECSTRING(settings,DefaultRadioFrequencies_SR);
                        tooltip = ECSTRING(settings,DefaultRadioFrequencies_SR_desc);
                        property = "TFAR_freq_sr";
                        control = "Edit"; //#TODO make custom control. Look at EditArray for example. Maybe multiple text boxes?
                        expression = QUOTE(SWCode);
                        defaultValue = "''";
                        typeName = "STRING";
                        unique = 0;
                        condition = "objectControllable + logicModule";
                    };
                    class TFAR_freq_lr {
                        displayName = ECSTRING(settings,DefaultRadioFrequencies_LR);
                        tooltip = ECSTRING(settings,DefaultRadioFrequencies_LR_desc);
                        property = "TFAR_freq_lr";
                        control = "Edit";
                        expression = QUOTE(LRCode);
                        defaultValue = "''";
                        typeName = "STRING";
                        unique = 0;
                        condition = "objectControllable + logicModule";
                    };
                    class TFAR_VehicleIDOverride {
                        property = "TFAR_VehicleIDOverride";
                        control = "EditShort";
                        displayName = "$STR_TFAR_Vehicle_ID_override";
                        tooltip = "$STR_TFAR_Vehicle_ID_override_desc";
                        expression = QUOTE(if !(_value isEqualTo '') then {_this setVariable [ARR_3('TFAR_vehicleIDOverride',_value,true)]};);
                        typeName = "STRING";
                        validate = "none";
                        condition = "objectVehicle";
                        defaultValue = "''";
                    };
                    class TFAR_defaultIntercomSlot {
                        property = "TFAR_defaultIntercomSlot";
                        control = "EditShort";
                        displayName = "$STR_TFAR_Intercom_Channel_Default";
                        tooltip = "$STR_TFAR_Intercom_Channel_Default_Desc";
                        expression = QUOTE(diag_log [ARR_2('defaultIntercomSlot', _value)]; if (_value != -2) then {_this setVariable [ARR_3('TFAR_defaultIntercomSlot',_value,true)]};);
                        typeName = "NUMBER";
                        validate = "number";
                        condition = "objectVehicle";
                        defaultValue = "-2";
                    };
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class TFAR_attributes {
                displayName = ECSTRING(core,3DEN_Properties);
                collapsed = 1;
                class Attributes {
                    class TFAR_freq_sr {
                        displayName = ECSTRING(settings,DefaultRadioFrequencies_SR);
                        tooltip = ECSTRING(settings,DefaultRadioFrequencies_SR_desc);
                        property = "TFAR_freq_sr";
                        expression = QUOTE(SWCode);
                        control = "Edit";
                        defaultValue = "''";
                        typeName = "STRING";
                        unique = 0;
                    };
                    class TFAR_freq_lr {
                        displayName = ECSTRING(settings,DefaultRadioFrequencies_LR);
                        tooltip = ECSTRING(settings,DefaultRadioFrequencies_LR_desc);
                        property = "TFAR_freq_lr";
                        expression = QUOTE(LRCode);
                        control = "Edit";
                        defaultValue = "''";
                        typeName = "STRING";
                        unique = 0;
                    };
                };
            };
        };
    };
};
