/*
 * Copyright (C) 2023 Paranoid Android
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <string.h>

#include "system_properties/prop_imitation_hooks.h"

#define GMS_UNSTABLE "com.google.android.gms.unstable"

#define PROP_BUILD_ID "ro.build.id"
#define PROP_PIH_BUILD_ID "persist.sys.pihooks.build_id"

#define PROP_SECURITY_PATCH "ro.build.version.security_patch"
#define PROP_PIH_SECURITY_PATCH "persist.sys.pihooks.security_patch"

#define PROP_BOARD_FIRST_API_LEVEL "ro.board.first_api_level"
#define PROP_PRODUCT_FIRST_API_LEVEL "ro.product.first_api_level"
#define PROP_VENDOR_API_LEVEL "ro.vendor.api_level"
#define PROP_PIH_FIRST_API_LEVEL "persist.sys.pihooks.first_api_level"

void PropImitationHooks::OnFind(const char** name) {
  if (getprogname() == nullptr || strcmp(getprogname(), GMS_UNSTABLE) != 0) {
    return;
  }
  PIH_LOG("name is %s", *name);
  if (strcmp(*name, PROP_BUILD_ID) == 0) {
    *name = PROP_PIH_BUILD_ID;
  } else if (strcmp(*name, PROP_SECURITY_PATCH) == 0) {
    *name = PROP_PIH_SECURITY_PATCH;
  } else if (strcmp(*name, PROP_BOARD_FIRST_API_LEVEL) == 0) {
    *name = PROP_PIH_FIRST_API_LEVEL;
  } else if (strcmp(*name, PROP_PRODUCT_FIRST_API_LEVEL) == 0) {
    *name = PROP_PIH_FIRST_API_LEVEL;
  } else if (strcmp(*name, PROP_VENDOR_API_LEVEL) == 0) {
    *name = PROP_PIH_FIRST_API_LEVEL;
  } else {
    return;
  }
  PIH_LOG("name changed to %s", *name);
}
