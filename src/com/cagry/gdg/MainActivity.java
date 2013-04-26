package com.cagry.gdg;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.widget.TextView;

public class MainActivity extends Activity {
    
    static {
	System.loadLibrary("GdgDemo");
    }
    
    public static native String getNativeString();
    
    
    public static native int nativeSum(int x, int y);
    
    
    public static native int nativeArraySum(int[] x);

    
    public static native int nativePerformanceTest();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.activity_main);
	
	TextView textView = (TextView) findViewById(R.id.textViewResult);
	
	//TODO:Simple Native example
//	textView.setText(getNativeString());

	
	//TODO:Passing parameters to native
	textView.setText(String.valueOf(nativeSum(3,4)));

	
	//TODO:Passing Array to Native
//	int[] testArray = {1,2,3,4,5};
//	textView.setText(String.valueOf(nativeArraySum(testArray)));
	
	
	//TODO:Performance comparison between native and sdk 
//	long oldTime = System.currentTimeMillis();
////	nativePerformanceTest();
//	defaultPerformanceTest();
//	long newTime = System.currentTimeMillis();
//	textView.setText(String.valueOf(newTime - oldTime));
	
	
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
	// Inflate the menu; this adds items to the action bar if it is present.
	getMenuInflater().inflate(R.menu.activity_main, menu);
	return true;
    }
    
    private int defaultPerformanceTest(){
	
	int array[][] = new int[1920][1080];
	//SOBEL FILTER
	int filter[][] = {{ -1,  0,  1 },
			{ -2,  0,  2 },
			{ -1,  0,  1 }};
	
	for (int i = 0; i < 1080; i++) {
	    for(int j = 0; i < 1920; i++){
		array[i][j] = 0;
	    }
	}

	int pixel_value = 0;
	for (int y = 1; y < 1919; y++) {
	    for (int x = 1; x < 1079; x++) {
		pixel_value = 0;
		for (int j = -1; j <= 1; j++) {
		    for (int i = -1; i <= 1; i++) {
			pixel_value += filter[j + 1][i + 1] * array[y + j][x + i];
		    }
		}
	    }
	}
	
	return pixel_value;
    }

}
