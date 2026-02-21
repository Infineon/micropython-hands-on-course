/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/20/2026 19:47:48 UTC. Any changes will be lost.
* 
* Model ID  75a5daec-86b7-4627-81db-82efcf1bbdc1
* 
* Memory    Size                      Efficiency
* Buffers   8800 bytes (RAM)          73 %
* State     2608 bytes (RAM)          100 %
* Readonly  7828 bytes (Flash)        100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-small-accuracy-1
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
* Global average pooling 1D      [16]            float      dequeue
*    trainable = True
* Dense                          [5]             float      dequeue
*    units = 5
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[16,5]
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
* (ACC) Accuracy 97.115 %
* (F1S) F1 Score 95.884 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5248                0                1                0                3
* (FN) False Negative or Incorrect Negative Prediction                7               33               35               33               48
* (FP) False Positive or Incorrect Positive Prediction              149                2                5                0                0
* (TN) True Negative or Correct Negative Prediction                   4             5373             5367             5375             5357
* (TPR) True Positive Rate or Sensitivity, Recall               99.87 %           0.00 %           2.78 %           0.00 %           5.88 %
* (TNR) True Negative Rate or Specificity, Selectivity           2.61 %          99.96 %          99.91 %         100.00 %         100.00 %
* (PPV) Positive Predictive Value or Precision                  97.24 %           0.00 %          16.67 %         100.00 %         100.00 %
* (NPV) Negative Predictive Value                               36.36 %          99.39 %          99.35 %          99.39 %          99.11 %
* (FNR) False Negative Rate or Miss Rate                         0.13 %         100.00 %          97.22 %         100.00 %          94.12 %
* (FPR) False Positive Rate or Fall-Out                         97.39 %           0.04 %           0.09 %           0.00 %           0.00 %
* (FDR) False Discovery Rate                                     2.76 %         100.00 %          83.33 %         100.00 %           0.00 %
* (FOR) False Omission Rate                                     63.64 %           0.61 %           0.65 %           0.61 %           0.89 %
* (F1S) F1 Score                                                98.54 %           0.00 %           4.76 %           0.00 %          11.11 %
*/


#define IMAI_TEST_AVG_ACC 0.9711538461538461 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9588425956199071 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5248, FN: 7, FP: 149, TN: 4, TPR: 0.9986679352997, TNR: 0.0261437908496, PPV: 0.9723920696683, NPV: 0.3636363636363, FNR: 0.0013320647002, FPR: 0.9738562091503, FDR: 0.0276079303316, FOR: 0.6363636363636, F1S: 0.9853548629365, }, \
 {name: "On", TP: 3, FN: 48, FP: 0, TN: 5357, TPR: 0.0588235294117, TNR: 1, PPV: 1, NPV: 0.9911193339500, FNR: 0.9411764705882, FPR: 0, FDR: 0, FOR: 0.0088806660499, F1S: 0.1111111111111, }, \
 {name: "Off", TP: 0, FN: 33, FP: 0, TN: 5375, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9938979289940, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0061020710059, F1S: 0, }, \
 {name: "Dimmer", TP: 0, FN: 33, FP: 2, TN: 5373, TPR: 0, TNR: 0.9996279069767, PPV: 0, NPV: 0.9938956714761, FNR: 1, FPR: 0.0003720930232, FDR: 1, FOR: 0.0061043285238, F1S: 0, }, \
 {name: "Lighter", TP: 1, FN: 35, FP: 5, TN: 5367, TPR: 0.0277777777777, TNR: 0.9990692479523, PPV: 0.1666666666666, NPV: 0.9935209181784, FNR: 0.9722222222222, FPR: 0.0009307520476, FDR: 0.8333333333333, FOR: 0.0064790818215, F1S: 0.0476190476190, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 95.674 %
* (F1S) F1 Score 94.185 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19989                5               17                6               42
* (FN) False Negative or Incorrect Negative Prediction               84              138              177              182              326
* (FP) False Positive or Incorrect Positive Prediction              823               16               48               12                8
* (TN) True Negative or Correct Negative Prediction                  70            20807            20724            20766            20590
* (TPR) True Positive Rate or Sensitivity, Recall               99.58 %           3.50 %           8.76 %           3.19 %          11.41 %
* (TNR) True Negative Rate or Specificity, Selectivity           7.84 %          99.92 %          99.77 %          99.94 %          99.96 %
* (PPV) Positive Predictive Value or Precision                  96.05 %          23.81 %          26.15 %          33.33 %          84.00 %
* (NPV) Negative Predictive Value                               45.45 %          99.34 %          99.15 %          99.13 %          98.44 %
* (FNR) False Negative Rate or Miss Rate                         0.42 %          96.50 %          91.24 %          96.81 %          88.59 %
* (FPR) False Positive Rate or Fall-Out                         92.16 %           0.08 %           0.23 %           0.06 %           0.04 %
* (FDR) False Discovery Rate                                     3.95 %          76.19 %          73.85 %          66.67 %          16.00 %
* (FOR) False Omission Rate                                     54.55 %           0.66 %           0.85 %           0.87 %           1.56 %
* (F1S) F1 Score                                                97.78 %           6.10 %          13.13 %           5.83 %          20.10 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9567394829724316 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9418481043495109 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19989, FN: 84, FP: 823, TN: 70, TPR: 0.9958152742489, TNR: 0.0783874580067, PPV: 0.9604555064385, NPV: 0.4545454545454, FNR: 0.0041847257510, FPR: 0.9216125419932, FDR: 0.0395444935614, FOR: 0.5454545454545, F1S: 0.9778158248746, }, \
 {name: "On", TP: 42, FN: 326, FP: 8, TN: 20590, TPR: 0.1141304347826, TNR: 0.9996116127779, PPV: 0.84, NPV: 0.9844138458596, FNR: 0.8858695652173, FPR: 0.0003883872220, FDR: 0.16, FOR: 0.0155861541403, F1S: 0.2009569377990, }, \
 {name: "Off", TP: 6, FN: 182, FP: 12, TN: 20766, TPR: 0.0319148936170, TNR: 0.9994224660698, PPV: 0.3333333333333, NPV: 0.9913118197441, FNR: 0.9680851063829, FPR: 0.0005775339301, FDR: 0.6666666666666, FOR: 0.0086881802558, F1S: 0.0582524271844, }, \
 {name: "Dimmer", TP: 5, FN: 138, FP: 16, TN: 20807, TPR: 0.0349650349650, TNR: 0.9992316188829, PPV: 0.2380952380952, NPV: 0.9934113153497, FNR: 0.9650349650349, FPR: 0.0007683811170, FDR: 0.7619047619047, FOR: 0.0065886846502, F1S: 0.0609756097560, }, \
 {name: "Lighter", TP: 17, FN: 177, FP: 48, TN: 20724, TPR: 0.0876288659793, TNR: 0.9976891969959, PPV: 0.2615384615384, NPV: 0.9915315056695, FNR: 0.9123711340206, FPR: 0.0023108030040, FDR: 0.7384615384615, FOR: 0.0084684943304, F1S: 0.1312741312741, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 96.586 %
* (F1S) F1 Score 95.344 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5852                1                2                0                2
* (FN) False Negative or Incorrect Negative Prediction               23               47               46               38               53
* (FP) False Positive or Incorrect Positive Prediction              184                5               10                7                1
* (TN) True Negative or Correct Negative Prediction                   5             6011             6006             6019             6008
* (TPR) True Positive Rate or Sensitivity, Recall               99.61 %           2.08 %           4.17 %           0.00 %           3.64 %
* (TNR) True Negative Rate or Specificity, Selectivity           2.65 %          99.92 %          99.83 %          99.88 %          99.98 %
* (PPV) Positive Predictive Value or Precision                  96.95 %          16.67 %          16.67 %           0.00 %          66.67 %
* (NPV) Negative Predictive Value                               17.86 %          99.22 %          99.24 %          99.37 %          99.13 %
* (FNR) False Negative Rate or Miss Rate                         0.39 %          97.92 %          95.83 %         100.00 %          96.36 %
* (FPR) False Positive Rate or Fall-Out                         97.35 %           0.08 %           0.17 %           0.12 %           0.02 %
* (FDR) False Discovery Rate                                     3.05 %          83.33 %          83.33 %         100.00 %          33.33 %
* (FOR) False Omission Rate                                     82.14 %           0.78 %           0.76 %           0.63 %           0.87 %
* (F1S) F1 Score                                                98.26 %           3.70 %           6.67 %           0.00 %           6.90 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9658641160949868 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9534416032568552 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5852, FN: 23, FP: 184, TN: 5, TPR: 0.9960851063829, TNR: 0.0264550264550, PPV: 0.9695162359178, NPV: 0.1785714285714, FNR: 0.0039148936170, FPR: 0.9735449735449, FDR: 0.0304837640821, FOR: 0.8214285714285, F1S: 0.9826211065401, }, \
 {name: "On", TP: 2, FN: 53, FP: 1, TN: 6008, TPR: 0.0363636363636, TNR: 0.9998335829588, PPV: 0.6666666666666, NPV: 0.9912555683880, FNR: 0.9636363636363, FPR: 0.0001664170411, FDR: 0.3333333333333, FOR: 0.0087444316119, F1S: 0.0689655172413, }, \
 {name: "Off", TP: 0, FN: 38, FP: 7, TN: 6019, TPR: 0, TNR: 0.9988383670760, PPV: 0, NPV: 0.9937262671289, FNR: 1, FPR: 0.0011616329239, FDR: 1, FOR: 0.0062737328710, F1S: 0, }, \
 {name: "Dimmer", TP: 1, FN: 47, FP: 5, TN: 6011, TPR: 0.0208333333333, TNR: 0.9991688829787, PPV: 0.1666666666666, NPV: 0.9922416639154, FNR: 0.9791666666666, FPR: 0.0008311170212, FDR: 0.8333333333333, FOR: 0.0077583360845, F1S: 0.0370370370370, }, \
 {name: "Lighter", TP: 2, FN: 46, FP: 10, TN: 6006, TPR: 0.0416666666666, TNR: 0.9983377659574, PPV: 0.1666666666666, NPV: 0.9923992068737, FNR: 0.9583333333333, FPR: 0.0016622340425, FDR: 0.8333333333333, FOR: 0.0076007931262, F1S: 0.0666666666666, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xec, 0xda, 0xa5, 0x75, 0xb7, 0x86, 0x27, 0x46, 0x81, 0xdb, 0x82, 0xef, 0xcf, 0x1b, 0xbd, 0xc1}

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

#define IMAI_KEY_MAX (33)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
