/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/20/2026 17:30:32 UTC. Any changes will be lost.
* 
* Model ID  761f2975-e94b-455b-aabb-503fd0aae629
* 
* Memory    Size                      Efficiency
* Buffers   8800 bytes (RAM)          73 %
* State     2608 bytes (RAM)          100 %
* Readonly  26836 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-accuracy-1
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
* Convolution 1D                 [50,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,16]
* Batch Normalization            [50,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [50,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [50,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [50,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [50,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [50,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [50,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [50,16]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [25,16]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
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
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
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
* Max pooling 1D                 [12,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [5]             float      dequeue
*    units = 5
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,5]
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
* (ACC) Accuracy 97.171 %
* (F1S) F1 Score 96.482 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5229                5                5                8                8
* (FN) False Negative or Incorrect Negative Prediction               26               28               31               25               43
* (FP) False Positive or Incorrect Positive Prediction              127                6                6               12                2
* (TN) True Negative or Correct Negative Prediction                  26             5369             5366             5363             5355
* (TPR) True Positive Rate or Sensitivity, Recall               99.51 %          15.15 %          13.89 %          24.24 %          15.69 %
* (TNR) True Negative Rate or Specificity, Selectivity          16.99 %          99.89 %          99.89 %          99.78 %          99.96 %
* (PPV) Positive Predictive Value or Precision                  97.63 %          45.45 %          45.45 %          40.00 %          80.00 %
* (NPV) Negative Predictive Value                               50.00 %          99.48 %          99.43 %          99.54 %          99.20 %
* (FNR) False Negative Rate or Miss Rate                         0.49 %          84.85 %          86.11 %          75.76 %          84.31 %
* (FPR) False Positive Rate or Fall-Out                         83.01 %           0.11 %           0.11 %           0.22 %           0.04 %
* (FDR) False Discovery Rate                                     2.37 %          54.55 %          54.55 %          60.00 %          20.00 %
* (FOR) False Omission Rate                                     50.00 %           0.52 %           0.57 %           0.46 %           0.80 %
* (F1S) F1 Score                                                98.56 %          22.73 %          21.28 %          30.19 %          26.23 %
*/


#define IMAI_TEST_AVG_ACC 0.9717085798816568 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9648163918743571 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5229, FN: 26, FP: 127, TN: 26, TPR: 0.9950523311132, TNR: 0.1699346405228, PPV: 0.9762882748319, NPV: 0.5, FNR: 0.0049476688867, FPR: 0.8300653594771, FDR: 0.0237117251680, FOR: 0.5, F1S: 0.9855810008481, }, \
 {name: "On", TP: 8, FN: 43, FP: 2, TN: 5355, TPR: 0.1568627450980, TNR: 0.9996266567108, PPV: 0.8, NPV: 0.9920340866987, FNR: 0.8431372549019, FPR: 0.0003733432891, FDR: 0.2, FOR: 0.0079659133012, F1S: 0.2622950819672, }, \
 {name: "Off", TP: 8, FN: 25, FP: 12, TN: 5363, TPR: 0.2424242424242, TNR: 0.9977674418604, PPV: 0.4, NPV: 0.9953600593912, FNR: 0.7575757575757, FPR: 0.0022325581395, FDR: 0.6, FOR: 0.0046399406087, F1S: 0.3018867924528, }, \
 {name: "Dimmer", TP: 5, FN: 28, FP: 6, TN: 5369, TPR: 0.1515151515151, TNR: 0.9988837209302, PPV: 0.4545454545454, NPV: 0.9948119325551, FNR: 0.8484848484848, FPR: 0.0011162790697, FDR: 0.5454545454545, FOR: 0.0051880674448, F1S: 0.2272727272727, }, \
 {name: "Lighter", TP: 5, FN: 31, FP: 6, TN: 5366, TPR: 0.1388888888888, TNR: 0.9988830975428, PPV: 0.4545454545454, NPV: 0.9942560681860, FNR: 0.8611111111111, FPR: 0.0011169024571, FDR: 0.5454545454545, FOR: 0.0057439318139, F1S: 0.2127659574468, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 96.814 %
* (F1S) F1 Score 96.724 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19788               96               83              128              203
* (FN) False Negative or Incorrect Negative Prediction              285               47              111               60              165
* (FP) False Positive or Incorrect Positive Prediction              377               86               60               80               65
* (TN) True Negative or Correct Negative Prediction                 516            20737            20712            20698            20533
* (TPR) True Positive Rate or Sensitivity, Recall               98.58 %          67.13 %          42.78 %          68.09 %          55.16 %
* (TNR) True Negative Rate or Specificity, Selectivity          57.78 %          99.59 %          99.71 %          99.61 %          99.68 %
* (PPV) Positive Predictive Value or Precision                  98.13 %          52.75 %          58.04 %          61.54 %          75.75 %
* (NPV) Negative Predictive Value                               64.42 %          99.77 %          99.47 %          99.71 %          99.20 %
* (FNR) False Negative Rate or Miss Rate                         1.42 %          32.87 %          57.22 %          31.91 %          44.84 %
* (FPR) False Positive Rate or Fall-Out                         42.22 %           0.41 %           0.29 %           0.39 %           0.32 %
* (FDR) False Discovery Rate                                     1.87 %          47.25 %          41.96 %          38.46 %          24.25 %
* (FOR) False Omission Rate                                     35.58 %           0.23 %           0.53 %           0.29 %           0.80 %
* (F1S) F1 Score                                                98.35 %          59.08 %          49.26 %          64.65 %          63.84 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9681388915386817 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9672446446841126 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19788, FN: 285, FP: 377, TN: 516, TPR: 0.9858018233447, TNR: 0.5778275475923, PPV: 0.9813042400198, NPV: 0.6441947565543, FNR: 0.0141981766552, FPR: 0.4221724524076, FDR: 0.0186957599801, FOR: 0.3558052434456, F1S: 0.9835478900541, }, \
 {name: "On", TP: 203, FN: 165, FP: 65, TN: 20533, TPR: 0.5516304347826, TNR: 0.9968443538207, PPV: 0.7574626865671, NPV: 0.9920282152865, FNR: 0.4483695652173, FPR: 0.0031556461792, FDR: 0.2425373134328, FOR: 0.0079717847134, F1S: 0.6383647798742, }, \
 {name: "Off", TP: 128, FN: 60, FP: 80, TN: 20698, TPR: 0.6808510638297, TNR: 0.9961497737992, PPV: 0.6153846153846, NPV: 0.9971095481260, FNR: 0.3191489361702, FPR: 0.0038502262007, FDR: 0.3846153846153, FOR: 0.0028904518739, F1S: 0.6464646464646, }, \
 {name: "Dimmer", TP: 96, FN: 47, FP: 86, TN: 20737, TPR: 0.6713286713286, TNR: 0.9958699514959, PPV: 0.5274725274725, NPV: 0.9977386451116, FNR: 0.3286713286713, FPR: 0.0041300485040, FDR: 0.4725274725274, FOR: 0.0022613548883, F1S: 0.5907692307692, }, \
 {name: "Lighter", TP: 83, FN: 111, FP: 60, TN: 20712, TPR: 0.4278350515463, TNR: 0.9971114962449, PPV: 0.5804195804195, NPV: 0.9946693560005, FNR: 0.5721649484536, FPR: 0.0028885037550, FDR: 0.4195804195804, FOR: 0.0053306439994, F1S: 0.4925816023738, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 96.834 %
* (F1S) F1 Score 96.150 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5837                6                7               13                9
* (FN) False Negative or Incorrect Negative Prediction               38               42               41               25               46
* (FP) False Positive or Incorrect Positive Prediction              150               10               15               12                5
* (TN) True Negative or Correct Negative Prediction                  39             6006             6001             6014             6004
* (TPR) True Positive Rate or Sensitivity, Recall               99.35 %          12.50 %          14.58 %          34.21 %          16.36 %
* (TNR) True Negative Rate or Specificity, Selectivity          20.63 %          99.83 %          99.75 %          99.80 %          99.92 %
* (PPV) Positive Predictive Value or Precision                  97.49 %          37.50 %          31.82 %          52.00 %          64.29 %
* (NPV) Negative Predictive Value                               50.65 %          99.31 %          99.32 %          99.59 %          99.24 %
* (FNR) False Negative Rate or Miss Rate                         0.65 %          87.50 %          85.42 %          65.79 %          83.64 %
* (FPR) False Positive Rate or Fall-Out                         79.37 %           0.17 %           0.25 %           0.20 %           0.08 %
* (FDR) False Discovery Rate                                     2.51 %          62.50 %          68.18 %          48.00 %          35.71 %
* (FOR) False Omission Rate                                     49.35 %           0.69 %           0.68 %           0.41 %           0.76 %
* (F1S) F1 Score                                                98.42 %          18.75 %          20.00 %          41.27 %          26.09 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9683377308707124 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9614970161301672 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5837, FN: 38, FP: 150, TN: 39, TPR: 0.9935319148936, TNR: 0.2063492063492, PPV: 0.9749457157173, NPV: 0.5064935064935, FNR: 0.0064680851063, FPR: 0.7936507936507, FDR: 0.0250542842826, FOR: 0.4935064935064, F1S: 0.9841510706457, }, \
 {name: "On", TP: 9, FN: 46, FP: 5, TN: 6004, TPR: 0.1636363636363, TNR: 0.9991679147944, PPV: 0.6428571428571, NPV: 0.9923966942148, FNR: 0.8363636363636, FPR: 0.0008320852055, FDR: 0.3571428571428, FOR: 0.0076033057851, F1S: 0.2608695652173, }, \
 {name: "Off", TP: 13, FN: 25, FP: 12, TN: 6014, TPR: 0.3421052631578, TNR: 0.9980086292731, PPV: 0.52, NPV: 0.9958602417618, FNR: 0.6578947368421, FPR: 0.0019913707268, FDR: 0.48, FOR: 0.0041397582381, F1S: 0.4126984126984, }, \
 {name: "Dimmer", TP: 6, FN: 42, FP: 10, TN: 6006, TPR: 0.125, TNR: 0.9983377659574, PPV: 0.375, NPV: 0.9930555555555, FNR: 0.875, FPR: 0.0016622340425, FDR: 0.625, FOR: 0.0069444444444, F1S: 0.1875, }, \
 {name: "Lighter", TP: 7, FN: 41, FP: 15, TN: 6001, TPR: 0.1458333333333, TNR: 0.9975066489361, PPV: 0.3181818181818, NPV: 0.9932141674942, FNR: 0.8541666666666, FPR: 0.0024933510638, FDR: 0.6818181818181, FOR: 0.0067858325057, F1S: 0.2, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x75, 0x29, 0x1f, 0x76, 0x4b, 0xe9, 0x5b, 0x45, 0xaa, 0xbb, 0x50, 0x3f, 0xd0, 0xaa, 0xe6, 0x29}

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

#define IMAI_KEY_MAX (49)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
