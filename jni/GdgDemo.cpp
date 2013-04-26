#include <GdgDemo.h>

JNIEXPORT jstring JNICALL Java_com_cagry_gdg_MainActivity_getNativeString(JNIEnv * env, jobject jObj) {

	return env->NewStringUTF("HELLO FROM NATIVE!");
}

JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativeSum(JNIEnv * env, jobject jObj, jint x, jint y) {

	return x + y;
}

JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativeArraySum(JNIEnv * env, jobject jObj, jintArray arr) {

	jsize arrayLength =  env->GetArrayLength(arr);
	jint buf[arrayLength];
	jint i, sum = 0;
	env->GetIntArrayRegion(arr, 0, arrayLength, buf);
	for (i = 0; i < arrayLength; i++) {
		sum += buf[i];
	}
	return sum;
}

JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativePerformanceTest(JNIEnv * env, jobject jObj) {

	int array[1920][1080];
	//SOBEL FILTER
	int filter[3][3] = {{ -1,  0,  1 },
						{ -2,  0,  2 },
						{ -1,  0,  1 }};

	for (int i = 0; i < 1080; i++) {
		for(int j = 0; i < 1920; i++){
			array[j][i] = 0;
		}
	}

	int pixel_value;
	for (int y = 1; y < 1919; y++) {
		for (int x = 1; x < 1079; x++) {
			pixel_value = 0.0;
			for (int j = -1; j <= 1; j++) {
				for (int i = -1; i <= 1; i++) {
					pixel_value += filter[j + 1][i + 1] * array[y + j][x + i];
				}
			}
		}
	}

	return pixel_value;
}
