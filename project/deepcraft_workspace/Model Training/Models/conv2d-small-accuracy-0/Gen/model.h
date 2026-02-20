/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/20/2026 17:32:15 UTC. Any changes will be lost.
* 
* Model ID  b1cf89c0-7b51-48b6-824f-fc0eaa2ac094
* 
* Memory    Size                      Efficiency
* Buffers   28800 bytes (RAM)         100 %
* State     2608 bytes (RAM)          100 %
* Readonly  94080 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv2d-small-accuracy-0
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
* Reshape                        [100,6,1]       float      dequeue
*    shape = [100,6,1]
*    trainable = True
* Convolution 2D                 [50,3,12]       float      dequeue
*    filters = 12
*    kernel_size = [5,5]
*    strides = [2,2]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,5,1,12]
* Batch Normalization            [50,3,12]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[12]
*    beta = float[12]
*    mean = float[12]
*    variance = float[12]
* Activation                     [50,3,12]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,24]       float      dequeue
*    filters = 24
*    kernel_size = [5,5]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,5,12,24]
* Batch Normalization            [50,3,24]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[24]
*    beta = float[24]
*    mean = float[24]
*    variance = float[24]
* Activation                     [50,3,24]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,24]       float      dequeue
*    filters = 24
*    kernel_size = [5,5]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,5,24,24]
* Batch Normalization            [50,3,24]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[24]
*    beta = float[24]
*    mean = float[24]
*    variance = float[24]
* Activation                     [50,3,24]       float      dequeue
*    activation = relu
*    trainable = True
* Global average pooling 2D      [24]            float      dequeue
* Dense                          [50]            float      dequeue
*    units = 50
*    use_bias = False
*    activation = linear
*    trainable = True
*    weight = float[24,50]
* Batch Normalization            [50]            float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 1
*    gamma = float[50]
*    beta = float[50]
*    mean = float[50]
*    variance = float[50]
* Activation                     [50]            float      dequeue
*    activation = relu
*    trainable = True
* Dropout                        [50]            float      dequeue
*    rate = 0.1
*    trainable = True
* Dense                          [5]             float      dequeue
*    units = 5
*    use_bias = False
*    activation = linear
*    trainable = True
*    weight = float[50,5]
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
* (ACC) Accuracy 97.226 %
* (F1S) F1 Score 96.150 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5245                1                0                0               12
* (FN) False Negative or Incorrect Negative Prediction               10               32               36               33               39
* (FP) False Positive or Incorrect Positive Prediction              140                1                0                0                9
* (TN) True Negative or Correct Negative Prediction                  13             5374             5372             5375             5348
* (TPR) True Positive Rate or Sensitivity, Recall               99.81 %           3.03 %           0.00 %           0.00 %          23.53 %
* (TNR) True Negative Rate or Specificity, Selectivity           8.50 %          99.98 %         100.00 %         100.00 %          99.83 %
* (PPV) Positive Predictive Value or Precision                  97.40 %          50.00 %         100.00 %         100.00 %          57.14 %
* (NPV) Negative Predictive Value                               56.52 %          99.41 %          99.33 %          99.39 %          99.28 %
* (FNR) False Negative Rate or Miss Rate                         0.19 %          96.97 %         100.00 %         100.00 %          76.47 %
* (FPR) False Positive Rate or Fall-Out                         91.50 %           0.02 %           0.00 %           0.00 %           0.17 %
* (FDR) False Discovery Rate                                     2.60 %          50.00 %         100.00 %         100.00 %          42.86 %
* (FOR) False Omission Rate                                     43.48 %           0.59 %           0.67 %           0.61 %           0.72 %
* (F1S) F1 Score                                                98.59 %           5.71 %           0.00 %           0.00 %          33.33 %
*/


#define IMAI_TEST_AVG_ACC 0.9722633136094675 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9615018616252169 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5245, FN: 10, FP: 140, TN: 13, TPR: 0.9980970504281, TNR: 0.0849673202614, PPV: 0.9740018570102, NPV: 0.5652173913043, FNR: 0.0019029495718, FPR: 0.9150326797385, FDR: 0.0259981429897, FOR: 0.4347826086956, F1S: 0.9859022556390, }, \
 {name: "On", TP: 12, FN: 39, FP: 9, TN: 5348, TPR: 0.2352941176470, TNR: 0.9983199551988, PPV: 0.5714285714285, NPV: 0.9927603489883, FNR: 0.7647058823529, FPR: 0.0016800448011, FDR: 0.4285714285714, FOR: 0.0072396510116, F1S: 0.3333333333333, }, \
 {name: "Off", TP: 0, FN: 33, FP: 0, TN: 5375, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9938979289940, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0061020710059, F1S: 0, }, \
 {name: "Dimmer", TP: 1, FN: 32, FP: 1, TN: 5374, TPR: 0.0303030303030, TNR: 0.9998139534883, PPV: 0.5, NPV: 0.9940806511283, FNR: 0.9696969696969, FPR: 0.0001860465116, FDR: 0.5, FOR: 0.0059193488716, F1S: 0.0571428571428, }, \
 {name: "Lighter", TP: 0, FN: 36, FP: 0, TN: 5372, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9933431952662, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0066568047337, F1S: 0, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 95.822 %
* (F1S) F1 Score 94.698 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19909               18                3                2              158
* (FN) False Negative or Incorrect Negative Prediction              164              125              191              186              210
* (FP) False Positive or Incorrect Positive Prediction              712               30                1                1              132
* (TN) True Negative or Correct Negative Prediction                 181            20793            20771            20777            20466
* (TPR) True Positive Rate or Sensitivity, Recall               99.18 %          12.59 %           1.55 %           1.06 %          42.93 %
* (TNR) True Negative Rate or Specificity, Selectivity          20.27 %          99.86 %         100.00 %         100.00 %          99.36 %
* (PPV) Positive Predictive Value or Precision                  96.55 %          37.50 %          75.00 %          66.67 %          54.48 %
* (NPV) Negative Predictive Value                               52.46 %          99.40 %          99.09 %          99.11 %          98.98 %
* (FNR) False Negative Rate or Miss Rate                         0.82 %          87.41 %          98.45 %          98.94 %          57.07 %
* (FPR) False Positive Rate or Fall-Out                         79.73 %           0.14 %           0.00 %           0.00 %           0.64 %
* (FDR) False Discovery Rate                                     3.45 %          62.50 %          25.00 %          33.33 %          45.52 %
* (FOR) False Omission Rate                                     47.54 %           0.60 %           0.91 %           0.89 %           1.02 %
* (F1S) F1 Score                                                97.85 %          18.85 %           3.03 %           2.09 %          48.02 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9582180673471334 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9469806633892011 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19909, FN: 164, FP: 712, TN: 181, TPR: 0.9918298211527, TNR: 0.2026875699888, PPV: 0.9654720915571, NPV: 0.5246376811594, FNR: 0.0081701788472, FPR: 0.7973124300111, FDR: 0.0345279084428, FOR: 0.4753623188405, F1S: 0.9784734850346, }, \
 {name: "On", TP: 158, FN: 210, FP: 132, TN: 20466, TPR: 0.4293478260869, TNR: 0.9935916108360, PPV: 0.5448275862068, NPV: 0.9898432965757, FNR: 0.5706521739130, FPR: 0.0064083891639, FDR: 0.4551724137931, FOR: 0.0101567034242, F1S: 0.4802431610942, }, \
 {name: "Off", TP: 2, FN: 186, FP: 1, TN: 20777, TPR: 0.0106382978723, TNR: 0.9999518721724, PPV: 0.6666666666666, NPV: 0.9911272241568, FNR: 0.9893617021276, FPR: 4.8127827509866, FDR: 0.3333333333333, FOR: 0.0088727758431, F1S: 0.0209424083769, }, \
 {name: "Dimmer", TP: 18, FN: 125, FP: 30, TN: 20793, TPR: 0.1258741258741, TNR: 0.9985592854055, PPV: 0.375, NPV: 0.9940242853045, FNR: 0.8741258741258, FPR: 0.0014407145944, FDR: 0.625, FOR: 0.0059757146954, F1S: 0.1884816753926, }, \
 {name: "Lighter", TP: 3, FN: 191, FP: 1, TN: 20771, TPR: 0.0154639175257, TNR: 0.9999518582707, PPV: 0.75, NPV: 0.9908882740196, FNR: 0.9845360824742, FPR: 4.8141729250914, FDR: 0.25, FOR: 0.0091117259803, F1S: 0.0303030303030, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 96.636 %
* (F1S) F1 Score 95.581 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5841                2                0                0               17
* (FN) False Negative or Incorrect Negative Prediction               34               46               48               38               38
* (FP) False Positive or Incorrect Positive Prediction              170                4                0                0               30
* (TN) True Negative or Correct Negative Prediction                  19             6012             6016             6026             5979
* (TPR) True Positive Rate or Sensitivity, Recall               99.42 %           4.17 %           0.00 %           0.00 %          30.91 %
* (TNR) True Negative Rate or Specificity, Selectivity          10.05 %          99.93 %         100.00 %         100.00 %          99.50 %
* (PPV) Positive Predictive Value or Precision                  97.17 %          33.33 %         100.00 %         100.00 %          36.17 %
* (NPV) Negative Predictive Value                               35.85 %          99.24 %          99.21 %          99.37 %          99.37 %
* (FNR) False Negative Rate or Miss Rate                         0.58 %          95.83 %         100.00 %         100.00 %          69.09 %
* (FPR) False Positive Rate or Fall-Out                         89.95 %           0.07 %           0.00 %           0.00 %           0.50 %
* (FDR) False Discovery Rate                                     2.83 %          66.67 %         100.00 %         100.00 %          63.83 %
* (FOR) False Omission Rate                                     64.15 %           0.76 %           0.79 %           0.63 %           0.63 %
* (F1S) F1 Score                                                98.28 %           7.41 %           0.00 %           0.00 %          33.33 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.966358839050132 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9558139802471175 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5841, FN: 34, FP: 170, TN: 19, TPR: 0.9942127659574, TNR: 0.1005291005291, PPV: 0.9717185160539, NPV: 0.3584905660377, FNR: 0.0057872340425, FPR: 0.8994708994708, FDR: 0.0282814839460, FOR: 0.6415094339622, F1S: 0.9828369510348, }, \
 {name: "On", TP: 17, FN: 38, FP: 30, TN: 5979, TPR: 0.3090909090909, TNR: 0.9950074887668, PPV: 0.3617021276595, NPV: 0.9936845604121, FNR: 0.6909090909090, FPR: 0.0049925112331, FDR: 0.6382978723404, FOR: 0.0063154395878, F1S: 0.3333333333333, }, \
 {name: "Off", TP: 0, FN: 38, FP: 0, TN: 6026, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9937335092348, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0062664907651, F1S: 0, }, \
 {name: "Dimmer", TP: 2, FN: 46, FP: 4, TN: 6012, TPR: 0.0416666666666, TNR: 0.9993351063829, PPV: 0.3333333333333, NPV: 0.9924067348960, FNR: 0.9583333333333, FPR: 0.0006648936170, FDR: 0.6666666666666, FOR: 0.0075932651039, F1S: 0.0740740740740, }, \
 {name: "Lighter", TP: 0, FN: 48, FP: 0, TN: 6016, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9920844327176, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0079155672823, F1S: 0, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xc0, 0x89, 0xcf, 0xb1, 0x51, 0x7b, 0xb6, 0x48, 0x82, 0x4f, 0xfc, 0x0e, 0xaa, 0x2a, 0xc0, 0x94}

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

#define IMAI_KEY_MAX (37)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
