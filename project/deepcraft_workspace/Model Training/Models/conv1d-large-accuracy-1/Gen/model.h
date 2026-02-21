/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/20/2026 16:13:51 UTC. Any changes will be lost.
* 
* Model ID  ada42531-ac34-47f6-be9d-dca9a49bca79
* 
* Memory    Size                      Efficiency
* Buffers   15200 bytes (RAM)         84 %
* State     2608 bytes (RAM)          100 %
* Readonly  145812 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-large-accuracy-1
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | On
* 2           | Off
* 3           | Dimmer
* 4           | Lighter
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [100,6]         float      dequeue
*    window_shape = [100,6]
*    stride = 60
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [100,6]         float      dequeue
*    contextual_length_sec = 2
*    prediction_freq = 5
* Input Layer                    [100,6]         float      dequeue
*    shape = [100,6]
* Convolution 1D                 [50,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,32]
* Batch Normalization            [50,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [25,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [25,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,48]         float      dequeue
*    filters = 48
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,48]
* Batch Normalization            [25,48]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[48]
*    beta = float[48]
*    mean = float[48]
*    variance = float[48]
* Activation                     [25,48]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,48]         float      dequeue
*    filters = 48
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,48,48]
* Batch Normalization            [25,48]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[48]
*    beta = float[48]
*    mean = float[48]
*    variance = float[48]
* Activation                     [25,48]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,48]         float      dequeue
*    filters = 48
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,48,48]
* Batch Normalization            [25,48]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[48]
*    beta = float[48]
*    mean = float[48]
*    variance = float[48]
* Activation                     [25,48]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,48]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [12,48]         float      dequeue
*    filters = 48
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,48,48]
* Batch Normalization            [12,48]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[48]
*    beta = float[48]
*    mean = float[48]
*    variance = float[48]
* Activation                     [12,48]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [12,48]         float      dequeue
*    filters = 48
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,48,48]
* Batch Normalization            [12,48]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[48]
*    beta = float[48]
*    mean = float[48]
*    variance = float[48]
* Activation                     [12,48]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [6,48]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [48]            float      dequeue
*    trainable = True
* Dense                          [5]             float      dequeue
*    units = 5
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[48,5]
*    bias = float[5]
* Activation                     [5]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[5].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[2,3].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 97.892 %
* (F1S) F1 Score 97.571 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5233                8               22               17               14
* (FN) False Negative or Incorrect Negative Prediction               22               25               14               16               37
* (FP) False Positive or Incorrect Positive Prediction               82                6               17                8                1
* (TN) True Negative or Correct Negative Prediction                  71             5369             5355             5367             5356
* (TPR) True Positive Rate or Sensitivity, Recall               99.58 %          24.24 %          61.11 %          51.52 %          27.45 %
* (TNR) True Negative Rate or Specificity, Selectivity          46.41 %          99.89 %          99.68 %          99.85 %          99.98 %
* (PPV) Positive Predictive Value or Precision                  98.46 %          57.14 %          56.41 %          68.00 %          93.33 %
* (NPV) Negative Predictive Value                               76.34 %          99.54 %          99.74 %          99.70 %          99.31 %
* (FNR) False Negative Rate or Miss Rate                         0.42 %          75.76 %          38.89 %          48.48 %          72.55 %
* (FPR) False Positive Rate or Fall-Out                         53.59 %           0.11 %           0.32 %           0.15 %           0.02 %
* (FDR) False Discovery Rate                                     1.54 %          42.86 %          43.59 %          32.00 %           6.67 %
* (FOR) False Omission Rate                                     23.66 %           0.46 %           0.26 %           0.30 %           0.69 %
* (F1S) F1 Score                                                99.02 %          34.04 %          58.67 %          58.62 %          42.42 %
*/


#define IMAI_TEST_AVG_ACC 0.9789201183431953 // Accuracy
#define IMAI_TEST_AVG_F1S 0.975708285650779 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5233, FN: 22, FP: 82, TN: 71, TPR: 0.9958135109419, TNR: 0.4640522875816, PPV: 0.9845719661335, NPV: 0.7634408602150, FNR: 0.0041864890580, FPR: 0.5359477124183, FDR: 0.0154280338664, FOR: 0.2365591397849, F1S: 0.9901608325449, }, \
 {name: "On", TP: 14, FN: 37, FP: 1, TN: 5356, TPR: 0.2745098039215, TNR: 0.9998133283554, PPV: 0.9333333333333, NPV: 0.9931392545892, FNR: 0.7254901960784, FPR: 0.0001866716445, FDR: 0.0666666666666, FOR: 0.0068607454107, F1S: 0.4242424242424, }, \
 {name: "Off", TP: 17, FN: 16, FP: 8, TN: 5367, TPR: 0.5151515151515, TNR: 0.9985116279069, PPV: 0.68, NPV: 0.9970276797324, FNR: 0.4848484848484, FPR: 0.0014883720930, FDR: 0.32, FOR: 0.0029723202675, F1S: 0.5862068965517, }, \
 {name: "Dimmer", TP: 8, FN: 25, FP: 6, TN: 5369, TPR: 0.2424242424242, TNR: 0.9988837209302, PPV: 0.5714285714285, NPV: 0.9953652206154, FNR: 0.7575757575757, FPR: 0.0011162790697, FDR: 0.4285714285714, FOR: 0.0046347793845, F1S: 0.3404255319148, }, \
 {name: "Lighter", TP: 22, FN: 14, FP: 17, TN: 5355, TPR: 0.6111111111111, TNR: 0.9968354430379, PPV: 0.5641025641025, NPV: 0.9973924380704, FNR: 0.3888888888888, FPR: 0.0031645569620, FDR: 0.4358974358974, FOR: 0.0026075619295, F1S: 0.5866666666666, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 98.130 %
* (F1S) F1 Score 98.097 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19896              119              156              172              231
* (FN) False Negative or Incorrect Negative Prediction              177               24               38               16              137
* (FP) False Positive or Incorrect Positive Prediction              214               49               52               21               56
* (TN) True Negative or Correct Negative Prediction                 679            20774            20720            20757            20542
* (TPR) True Positive Rate or Sensitivity, Recall               99.12 %          83.22 %          80.41 %          91.49 %          62.77 %
* (TNR) True Negative Rate or Specificity, Selectivity          76.04 %          99.76 %          99.75 %          99.90 %          99.73 %
* (PPV) Positive Predictive Value or Precision                  98.94 %          70.83 %          75.00 %          89.12 %          80.49 %
* (NPV) Negative Predictive Value                               79.32 %          99.88 %          99.82 %          99.92 %          99.34 %
* (FNR) False Negative Rate or Miss Rate                         0.88 %          16.78 %          19.59 %           8.51 %          37.23 %
* (FPR) False Positive Rate or Fall-Out                         23.96 %           0.24 %           0.25 %           0.10 %           0.27 %
* (FDR) False Discovery Rate                                     1.06 %          29.17 %          25.00 %          10.88 %          19.51 %
* (FOR) False Omission Rate                                     20.68 %           0.12 %           0.18 %           0.08 %           0.66 %
* (F1S) F1 Score                                                99.03 %          76.53 %          77.61 %          90.29 %          70.53 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9813030621005437 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9809687330002196 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19896, FN: 177, FP: 214, TN: 679, TPR: 0.9911821850246, TNR: 0.7603583426651, PPV: 0.9893585280954, NPV: 0.7932242990654, FNR: 0.0088178149753, FPR: 0.2396416573348, FDR: 0.0106414719045, FOR: 0.2067757009345, F1S: 0.9902695169599, }, \
 {name: "On", TP: 231, FN: 137, FP: 56, TN: 20542, TPR: 0.6277173913043, TNR: 0.9972812894455, PPV: 0.8048780487804, NPV: 0.9933749214178, FNR: 0.3722826086956, FPR: 0.0027187105544, FDR: 0.1951219512195, FOR: 0.0066250785821, F1S: 0.7053435114503, }, \
 {name: "Off", TP: 172, FN: 16, FP: 21, TN: 20757, TPR: 0.9148936170212, TNR: 0.9989893156222, PPV: 0.8911917098445, NPV: 0.9992297694122, FNR: 0.0851063829787, FPR: 0.0010106843777, FDR: 0.1088082901554, FOR: 0.0007702305877, F1S: 0.9028871391076, }, \
 {name: "Dimmer", TP: 119, FN: 24, FP: 49, TN: 20774, TPR: 0.8321678321678, TNR: 0.9976468328290, PPV: 0.7083333333333, NPV: 0.9988460428887, FNR: 0.1678321678321, FPR: 0.0023531671709, FDR: 0.2916666666666, FOR: 0.0011539571112, F1S: 0.7652733118971, }, \
 {name: "Lighter", TP: 156, FN: 38, FP: 52, TN: 20720, TPR: 0.8041237113402, TNR: 0.9974966300789, PPV: 0.75, NPV: 0.9981693804798, FNR: 0.1958762886597, FPR: 0.0025033699210, FDR: 0.25, FOR: 0.0018306195201, F1S: 0.7761194029850, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 97.889 %
* (F1S) F1 Score 97.639 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5843               20               35               24               14
* (FN) False Negative or Incorrect Negative Prediction               32               28               13               14               41
* (FP) False Positive or Incorrect Positive Prediction               85                7               19               11                6
* (TN) True Negative or Correct Negative Prediction                 104             6009             5997             6015             6003
* (TPR) True Positive Rate or Sensitivity, Recall               99.46 %          41.67 %          72.92 %          63.16 %          25.45 %
* (TNR) True Negative Rate or Specificity, Selectivity          55.03 %          99.88 %          99.68 %          99.82 %          99.90 %
* (PPV) Positive Predictive Value or Precision                  98.57 %          74.07 %          64.81 %          68.57 %          70.00 %
* (NPV) Negative Predictive Value                               76.47 %          99.54 %          99.78 %          99.77 %          99.32 %
* (FNR) False Negative Rate or Miss Rate                         0.54 %          58.33 %          27.08 %          36.84 %          74.55 %
* (FPR) False Positive Rate or Fall-Out                         44.97 %           0.12 %           0.32 %           0.18 %           0.10 %
* (FDR) False Discovery Rate                                     1.43 %          25.93 %          35.19 %          31.43 %          30.00 %
* (FOR) False Omission Rate                                     23.53 %           0.46 %           0.22 %           0.23 %           0.68 %
* (F1S) F1 Score                                                99.01 %          53.33 %          68.63 %          65.75 %          37.33 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.978891820580475 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9763890993776597 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5843, FN: 32, FP: 85, TN: 104, TPR: 0.9945531914893, TNR: 0.5502645502645, PPV: 0.9856612685560, NPV: 0.7647058823529, FNR: 0.0054468085106, FPR: 0.4497354497354, FDR: 0.0143387314439, FOR: 0.2352941176470, F1S: 0.9900872659493, }, \
 {name: "On", TP: 14, FN: 41, FP: 6, TN: 6003, TPR: 0.2545454545454, TNR: 0.9990014977533, PPV: 0.7, NPV: 0.9932164129715, FNR: 0.7454545454545, FPR: 0.0009985022466, FDR: 0.3, FOR: 0.0067835870284, F1S: 0.3733333333333, }, \
 {name: "Off", TP: 24, FN: 14, FP: 11, TN: 6015, TPR: 0.6315789473684, TNR: 0.9981745768337, PPV: 0.6857142857142, NPV: 0.9976778901973, FNR: 0.3684210526315, FPR: 0.0018254231662, FDR: 0.3142857142857, FOR: 0.0023221098026, F1S: 0.6575342465753, }, \
 {name: "Dimmer", TP: 20, FN: 28, FP: 7, TN: 6009, TPR: 0.4166666666666, TNR: 0.9988364361702, PPV: 0.7407407407407, NPV: 0.9953619347357, FNR: 0.5833333333333, FPR: 0.0011635638297, FDR: 0.2592592592592, FOR: 0.0046380652642, F1S: 0.5333333333333, }, \
 {name: "Lighter", TP: 35, FN: 13, FP: 19, TN: 5997, TPR: 0.7291666666666, TNR: 0.9968417553191, PPV: 0.6481481481481, NPV: 0.9978369384359, FNR: 0.2708333333333, FPR: 0.0031582446808, FDR: 0.3518518518518, FOR: 0.0021630615640, F1S: 0.6862745098039, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x31, 0x25, 0xa4, 0xad, 0x34, 0xac, 0xf6, 0x47, 0xbe, 0x9d, 0xdc, 0xa9, 0xa4, 0x9b, 0xca, 0x79}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [2,3] (24 bytes)
#define IMAI_DATA_IN_COUNT (6)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [5] (20 bytes)
#define IMAI_DATA_OUT_COUNT (5)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (63)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
