LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := GdgDemo
LOCAL_SRC_FILES := GdgDemo.cpp
LOCAL_LDLIBS 	:= -llog

include $(BUILD_SHARED_LIBRARY)
