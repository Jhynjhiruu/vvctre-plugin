// Copyright 2020 Valentin Vanelslande
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common_types.h"

#ifdef _WIN32
#define VVCTRE_PLUGIN_EXPORT __declspec(dllexport)
#else
#define VVCTRE_PLUGIN_EXPORT
#endif

static const char* required_function_names[] = {
    "vvctre_settings_set_file_path",
    "vvctre_settings_set_region_value",
};

typedef void (*vvctre_settings_set_file_path_t)(const char* value);
static vvctre_settings_set_file_path_t vvctre_settings_set_file_path;
typedef void (*vvctre_settings_set_region_value_t)(int value);
static vvctre_settings_set_region_value_t vvctre_settings_set_region_value;

VVCTRE_PLUGIN_EXPORT int GetRequiredFunctionCount() {
    return 2;
}

VVCTRE_PLUGIN_EXPORT const char** GetRequiredFunctionNames() {
    return required_function_names;
}
      
VVCTRE_PLUGIN_EXPORT void PluginLoaded(void* core, void* plugin_manager, void* required_functions[]) {
    vvctre_settings_set_file_path = (vvctre_settings_set_file_path_t)required_functions[0];
    vvctre_settings_set_region_value = (vvctre_settings_set_region_value_t)required_functions[1];
}

VVCTRE_PLUGIN_EXPORT void InitialSettingsOpening() {
    vvctre_settings_set_file_path("D:\\vvctre/user/nand/00000000000000000000000000000000/title/00040030/0000a102/content/0000000d.app");
    vvctre_settings_set_region_value(4);
}
