###############################################################################
#
# Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  * Neither the name of NVIDIA CORPORATION nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
###############################################################################
include ../Rules.mk

APP := v4l2

SRCS := \
	main.cpp\
	v4l2cap.cpp\
	pthread.cpp \
	$(wildcard $(CLASS_DIR)/*.cpp)

OBJS := $(SRCS:.cpp=.o)

CPPFLAGS += \
	-I"$(ALGO_CUDA_DIR)"\
	-I /usr/include

LDFLAGS += \
	-L "$(CUDA_PATH)/targets/aarch64-linux/lib"\
	-L /usr/lib\
	 -lopencv_core -lopencv_imgproc -lopencv_flann  -lopencv_highgui -lopencv_ml -lopencv_video  -lstdc++

OBJS += \
	

all: $(APP)

$(CLASS_DIR)/%.o: $(CLASS_DIR)/%.cpp
	$(MAKE) -C $(CLASS_DIR)

$(ALGO_CUDA_DIR)/%.o: $(ALGO_CUDA_DIR)/%.cpp
	$(MAKE) -C $(ALGO_CUDA_DIR)

$(ALGO_CUDA_DIR)/%.o: $(ALGO_CUDA_DIR)/%.cu
	$(MAKE) -C $(ALGO_CUDA_DIR)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $<

$(APP): $(OBJS)
	$(CPP) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -rf $(APP) $(OBJS)
