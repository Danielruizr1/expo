package abi33_0_0.org.unimodules.interfaces.facedetector;

import android.net.Uri;

import java.io.IOException;
import java.util.Map;

public interface FaceDetector {

  void detectFaces(Uri filePath, FacesDetectionCompleted listener, FaceDetectionError error) throws IOException;

  void detectFaces(byte[] imageData, int width, int height, int rotation, boolean mirrored, double scaleX, double scaleY,
                   FacesDetectionCompleted listener, FaceDetectionError error, FaceDetectionSkipped skipped);

  void setSettings(Map<String, Object> settings);

  void release();
}
