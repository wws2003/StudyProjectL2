package com.techburg.autospring.util;

import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;

public class FileUtil {
	public void getStringFromInputStream(InputStream inputStream, StringBuilder outputBuilder) throws Exception {
		int c;
		byte[] b = new byte[1024];
		while ((c = inputStream.read(b)) != -1) {
			String chunk = new String(b, 0, c);
			outputBuilder.append(chunk);
		}
	}
	
	public void writeStringToOutputStream(String output, OutputStream outputStream) throws Exception {
		byte[] outputByteArray = output.getBytes(Charset.forName("UTF-8"));
		outputStream.write(outputByteArray);
	}
}
