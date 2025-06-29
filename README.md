
# 🖐️ Hand Gesture Recognition using Decision Tree on ESP32-CAM

This project implements a real-time **hand gesture recognition system** using a **Decision Tree classifier** trained in Python and deployed on an **ESP32-CAM**. It uses **HOG (Histogram of Oriented Gradients)** for feature extraction and classifies gestures into 3 labels (`00500A`, `00500B`, `00500C`).

## 🔍 Overview

- 🧠 Trained a Decision Tree model using scikit-learn on extracted HOG features from hand gesture images.
- 📦 Model is exported as C++ code using `everywhereml` format, embedded into ESP32-CAM firmware.
- 🎥 ESP32-CAM captures hand image, extracts HOG features, and predicts gesture in real time.

## 🧠 Machine Learning Details

- **Feature extraction**: HOG with block size 8, 9 bins, resized to 28x28
- **Classifier**: DecisionTreeClassifier (`max_depth=30`)
- **Model output**: 3 classes with labels: `00500A`, `00500B`, `00500C`
- Model logic located in: `HogClassifier.h`

## 📦 Project Structure

```
├── decision.ipynb              # Python notebook for training Decision Tree & exporting model
├── ESP32CAM_Detection.ino      # Main Arduino sketch for ESP32-CAM (reads image, predicts)
├── HogPipeline.h               # HOG feature extraction pipeline
├── HogClassifier.h             # Decision Tree model in C++
├── README.md                   # Project documentation
```

## 🚀 How It Works

1. **Data preparation**: Hand gesture images collected and labeled.
2. **Feature extraction**: Convert grayscale, resize to 28×28, extract HOG features.
3. **Model training**: Decision Tree trained via `sklearn`, exported to C++.
4. **ESP32-CAM**:
    - Captures frame from camera.
    - Converts to grayscale, applies HOG, then predicts with the embedded model.
    - Returns class label via Serial output.

## 💻 Dependencies

### On PC (Python):
- Python ≥ 3.8
- `opencv-python`
- `scikit-learn`
- `joblib`, `numpy`
- `everywhereml` for model export

### On ESP32-CAM:
- Arduino core for ESP32
- `esp32cam` or `esp_camera` library

## 📷 Labels / Gestures

| Label    | Description       |
|----------|-------------------|
| 00500A   | (ký tự A)         |
| 00500B   | (Ký tự B)         |
| 00500C   | (Ký tự C)         |

## 🛠️ Getting Started

1. Train model with `decision.ipynb`.
2. Upload code to ESP32-CAM via Arduino IDE (`ESP32CAM_Detection.ino`).
3. Connect Serial Monitor to see predicted gesture output.
4. Test with hand gestures in front of the ESP32-CAM.

## 👤 Author

**Quyet Ba (aka NioDan-F)**  
📧 [quyet1hai@gmail.com](mailto:quyet1hai@gmail.com)
