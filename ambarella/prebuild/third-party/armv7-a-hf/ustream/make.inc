##
## prebuild/third-party/ustream/make.inc
##
## History:
##    2012/05/30 - [Cao Rongrong] Created file
##
## Copyright (C) 2012-2016, Ambarella, Inc.
##
## All rights reserved. No Part of this file may be reproduced, stored
## in a retrieval system, or transmitted, in any form, or by any means,
## electronic, mechanical, photocopying, recording, or otherwise,
## without the prior consent of Ambarella, Inc.
##

ifeq ($(CONFIG_AMBARELLA_USTREAM_SUPPORT), y)

LOCAL_PATH	:= $(call my-dir)

###
include $(CLEAR_VARS)

LOCAL_TARGET	:= prebuild_ustream
LOCAL_SRCS	:= usr

.PHONY: $(LOCAL_TARGET)

include $(BUILD_PREBUILD)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@echo "$@ is currently not available for hard-float."
#	$(call prebuild-links)
#	@echo "Copy $@ Done"

$(call add-target-into-build, $(LOCAL_TARGET))

endif
