# 🖐️ Hand Gesture Recognition using Decision Tree on ESP32-CAM
<p align="center">
  <img src="https://sdmntpreastus.oaiusercontent.com/files/00000000-0398-61f9-b45c-d387bab9f84f/raw?se=2025-08-21T15%3A19%3A06Z&sp=r&sv=2024-08-04&sr=b&scid=2e48d2dd-1df0-5fdc-9b9f-cddac9cb1a6c&skoid=02b7f7b5-29f8-416a-aeb6-99464748559d&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2025-08-20T21%3A31%3A58Z&ske=2025-08-21T21%3A31%3A58Z&sks=b&skv=2024-08-04&sig=Y7MtaOInKh3u5sD5ZZe1JleP1lxYTsfHaRi9dTvbu2o%3D" width="350"/>
</p>
This project implements a real-time **hand gesture recognition system** using a **Decision Tree classifier** trained in Python and deployed on an **ESP32-CAM**. It uses **HOG (Histogram of Oriented Gradients)** for feature extraction and classifies gestures into 3 labels corresponding to **hand signs for characters A, B, and C**.

---

## 🧪 Project Goal: Recognize 3 Hand Signs (A, B, C)

The system is designed to detect and classify static hand gestures that represent the letters:

| Label    | Hand Sign | Description |
|----------|-----------|-------------|
| 00500A   | ✋         | Letter A    |
| 00500B   | ✌️         | Letter B    |
| 00500C   | 👊         | Letter C    |

These labels are customizable depending on the collected dataset.

---

## 🔍 Overview

- 🧠 Trained a Decision Tree model using scikit-learn on extracted HOG features from hand gesture images.
- 📦 Model is exported as C++ code using `everywhereml` format, embedded into ESP32-CAM firmware.
- 🎥 ESP32-CAM captures hand image, extracts HOG features, and predicts gesture in real time.

---

## 🧠 Machine Learning Details

- **Feature extraction**: HOG with block size 8, 9 bins, resized to 28x28
- **Classifier**: DecisionTreeClassifier (`max_depth=30`)
- **Model output**: 3 classes with labels: `00500A`, `00500B`, `00500C`
- Model logic located in: `HogClassifier.h`

---

## 📎 Requirements

- To capture and process hand gesture images using ESP32-CAM, install the `ESP32` board via Arduino IDE and include **EloquentTinyML** and **esp_camera** libraries.
- To train the model and convert to C++, install the [`EverywhereML`](https://github.com/eloquentarduino/everywhereml-python) Python package.
- To run this project, any **ESP32-CAM** variant can be used, preferably one with external PSRAM:
  - [AI Thinker](https://docs.ai-thinker.com/en/esp32-cam)
  - [M5Stack ESP32-CAM](https://shop.m5stack.com/products/esp32-cam-board)
  - [Espressif official](https://www.espressif.com/en/products/devkits/esp32-devkitc/overview)

---

## 💻 Code

- [`ESP32CAM_Detection.ino`](ESP32CAM_Detection/[ino]-ESP32CAM_Detection.ino) – Main ESP32 sketch for capturing, processing, and predicting hand gestures.
- [`HogClassifier.h`](ESP32CAM_Detection/[h]-HogClassifier.h) – Contains the Decision Tree classifier generated from the Python notebook using EverywhereML.
- [`HogPipeline.h`](ESP32CAM_Detection/[h]-HogPipeline.h) – Contains the HOG feature extractor logic used on the ESP32.
- [`Detection_Hand_Train.ipynb`]([ipynb]-Detection_Hand_Train.ipynb) – Python notebook used to train the Decision Tree model and export it for C++ deployment.

---

## 📦 Project Structure

```
├── ESP32CAM_Colect Data/           # Dataset capture sketch (optional)
│   └── Collect Data.ino
├── ESP32CAM_Detection/             # ESP32 code for hand sign detection
│   ├── ESP32CAM_Detection.ino
│   ├── HogClassifier.h
│   └── HogPipeline.h
├── dataset_folder/                 # (Optional) Raw image dataset for training
├── Detection_Hand_Train.ipynb      # Jupyter Notebook for training
└── README.md                       # Project documentation
```

---

## 🚀 How It Works

1. **Data preparation**: Hand gesture images collected and labeled.
2. **Feature extraction**: Convert grayscale, resize to 28×28, extract HOG features.
3. **Model training**: Decision Tree trained via `sklearn`, exported to C++.
4. **ESP32-CAM**:
    - Captures frame from camera.
    - Converts to grayscale, applies HOG, then predicts with the embedded model.
    - Returns class label via Serial output.

---

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

---

## 👤 Author

**Quyet Ba (aka NioDan-F)**  
📧 [quyet1hai@gmail.com](mailto:quyet1hai@gmail.com)
