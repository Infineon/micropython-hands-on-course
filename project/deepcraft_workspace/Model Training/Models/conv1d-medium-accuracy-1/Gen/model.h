/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/20/2026 19:47:31 UTC. Any changes will be lost.
* 
* Model ID  fdd88b1c-49f1-4f4e-b556-6f84287d1595
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
* (ACC) Accuracy 97.245 %
* (F1S) F1 Score 96.231 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5245                0                2                1               11
* (FN) False Negative or Incorrect Negative Prediction               10               33               34               32               40
* (FP) False Positive or Incorrect Positive Prediction              139                1                3                4                2
* (TN) True Negative or Correct Negative Prediction                  14             5374             5369             5371             5355
* (TPR) True Positive Rate or Sensitivity, Recall               99.81 %           0.00 %           5.56 %           3.03 %          21.57 %
* (TNR) True Negative Rate or Specificity, Selectivity           9.15 %          99.98 %          99.94 %          99.93 %          99.96 %
* (PPV) Positive Predictive Value or Precision                  97.42 %           0.00 %          40.00 %          20.00 %          84.62 %
* (NPV) Negative Predictive Value                               58.33 %          99.39 %          99.37 %          99.41 %          99.26 %
* (FNR) False Negative Rate or Miss Rate                         0.19 %         100.00 %          94.44 %          96.97 %          78.43 %
* (FPR) False Positive Rate or Fall-Out                         90.85 %           0.02 %           0.06 %           0.07 %           0.04 %
* (FDR) False Discovery Rate                                     2.58 %         100.00 %          60.00 %          80.00 %          15.38 %
* (FOR) False Omission Rate                                     41.67 %           0.61 %           0.63 %           0.59 %           0.74 %
* (F1S) F1 Score                                                98.60 %           0.00 %           9.76 %           5.26 %          34.38 %
*/


#define IMAI_TEST_AVG_ACC 0.972448224852071 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9623120589141287 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5245, FN: 10, FP: 139, TN: 14, TPR: 0.9980970504281, TNR: 0.0915032679738, PPV: 0.9741827637444, NPV: 0.5833333333333, FNR: 0.0019029495718, FPR: 0.9084967320261, FDR: 0.0258172362555, FOR: 0.4166666666666, F1S: 0.9859949243349, }, \
 {name: "On", TP: 11, FN: 40, FP: 2, TN: 5355, TPR: 0.2156862745098, TNR: 0.9996266567108, PPV: 0.8461538461538, NPV: 0.9925857275254, FNR: 0.7843137254901, FPR: 0.0003733432891, FDR: 0.1538461538461, FOR: 0.0074142724745, F1S: 0.34375, }, \
 {name: "Off", TP: 1, FN: 32, FP: 4, TN: 5371, TPR: 0.0303030303030, TNR: 0.9992558139534, PPV: 0.2, NPV: 0.9940773644271, FNR: 0.9696969696969, FPR: 0.0007441860465, FDR: 0.8, FOR: 0.0059226355728, F1S: 0.0526315789473, }, \
 {name: "Dimmer", TP: 0, FN: 33, FP: 1, TN: 5374, TPR: 0, TNR: 0.9998139534883, PPV: 0, NPV: 0.9938968004438, FNR: 1, FPR: 0.0001860465116, FDR: 1, FOR: 0.0061031995561, F1S: 0, }, \
 {name: "Lighter", TP: 2, FN: 34, FP: 3, TN: 5369, TPR: 0.0555555555555, TNR: 0.9994415487714, PPV: 0.4, NPV: 0.9937071997038, FNR: 0.9444444444444, FPR: 0.0005584512285, FDR: 0.6, FOR: 0.0062928002961, F1S: 0.0975609756097, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 96.346 %
* (F1S) F1 Score 95.679 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19897               60                6               61              176
* (FN) False Negative or Incorrect Negative Prediction              176               83              188              127              192
* (FP) False Positive or Incorrect Positive Prediction              590               46                8               35               87
* (TN) True Negative or Correct Negative Prediction                 303            20777            20764            20743            20511
* (TPR) True Positive Rate or Sensitivity, Recall               99.12 %          41.96 %           3.09 %          32.45 %          47.83 %
* (TNR) True Negative Rate or Specificity, Selectivity          33.93 %          99.78 %          99.96 %          99.83 %          99.58 %
* (PPV) Positive Predictive Value or Precision                  97.12 %          56.60 %          42.86 %          63.54 %          66.92 %
* (NPV) Negative Predictive Value                               63.26 %          99.60 %          99.10 %          99.39 %          99.07 %
* (FNR) False Negative Rate or Miss Rate                         0.88 %          58.04 %          96.91 %          67.55 %          52.17 %
* (FPR) False Positive Rate or Fall-Out                         66.07 %           0.22 %           0.04 %           0.17 %           0.42 %
* (FDR) False Discovery Rate                                     2.88 %          43.40 %          57.14 %          36.46 %          33.08 %
* (FOR) False Omission Rate                                     36.74 %           0.40 %           0.90 %           0.61 %           0.93 %
* (F1S) F1 Score                                                98.11 %          48.19 %           5.77 %          42.96 %          55.78 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9634646570638176 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9567902651686335 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19897, FN: 176, FP: 590, TN: 303, TPR: 0.9912320031883, TNR: 0.3393057110862, PPV: 0.9712012495728, NPV: 0.6325678496868, FNR: 0.0087679968116, FPR: 0.6606942889137, FDR: 0.0287987504271, FOR: 0.3674321503131, F1S: 0.9811143984220, }, \
 {name: "On", TP: 176, FN: 192, FP: 87, TN: 20511, TPR: 0.4782608695652, TNR: 0.9957762889600, PPV: 0.6692015209125, NPV: 0.9907259817417, FNR: 0.5217391304347, FPR: 0.0042237110399, FDR: 0.3307984790874, FOR: 0.0092740182582, F1S: 0.5578446909667, }, \
 {name: "Off", TP: 61, FN: 127, FP: 35, TN: 20743, TPR: 0.3244680851063, TNR: 0.9983155260371, PPV: 0.6354166666666, NPV: 0.9939147101102, FNR: 0.6755319148936, FPR: 0.0016844739628, FDR: 0.3645833333333, FOR: 0.0060852898897, F1S: 0.4295774647887, }, \
 {name: "Dimmer", TP: 60, FN: 83, FP: 46, TN: 20777, TPR: 0.4195804195804, TNR: 0.9977909042885, PPV: 0.5660377358490, NPV: 0.9960210930009, FNR: 0.5804195804195, FPR: 0.0022090957114, FDR: 0.4339622641509, FOR: 0.0039789069990, F1S: 0.4819277108433, }, \
 {name: "Lighter", TP: 6, FN: 188, FP: 8, TN: 20764, TPR: 0.0309278350515, TNR: 0.9996148661659, PPV: 0.4285714285714, NPV: 0.9910271095838, FNR: 0.9690721649484, FPR: 0.0003851338340, FDR: 0.5714285714285, FOR: 0.0089728904161, F1S: 0.0576923076923, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 97.032 %
* (F1S) F1 Score 95.963 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5862                2                1                1               18
* (FN) False Negative or Incorrect Negative Prediction               13               46               47               37               37
* (FP) False Positive or Incorrect Positive Prediction              165                4                1                3                7
* (TN) True Negative or Correct Negative Prediction                  24             6012             6015             6023             6002
* (TPR) True Positive Rate or Sensitivity, Recall               99.78 %           4.17 %           2.08 %           2.63 %          32.73 %
* (TNR) True Negative Rate or Specificity, Selectivity          12.70 %          99.93 %          99.98 %          99.95 %          99.88 %
* (PPV) Positive Predictive Value or Precision                  97.26 %          33.33 %          50.00 %          25.00 %          72.00 %
* (NPV) Negative Predictive Value                               64.86 %          99.24 %          99.22 %          99.39 %          99.39 %
* (FNR) False Negative Rate or Miss Rate                         0.22 %          95.83 %          97.92 %          97.37 %          67.27 %
* (FPR) False Positive Rate or Fall-Out                         87.30 %           0.07 %           0.02 %           0.05 %           0.12 %
* (FDR) False Discovery Rate                                     2.74 %          66.67 %          50.00 %          75.00 %          28.00 %
* (FOR) False Omission Rate                                     35.14 %           0.76 %           0.78 %           0.61 %           0.61 %
* (F1S) F1 Score                                                98.50 %           7.41 %           4.00 %           4.76 %          45.00 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9703166226912929 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9596259391589578 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5862, FN: 13, FP: 165, TN: 24, TPR: 0.9977872340425, TNR: 0.1269841269841, PPV: 0.9726231956197, NPV: 0.6486486486486, FNR: 0.0022127659574, FPR: 0.8730158730158, FDR: 0.0273768043802, FOR: 0.3513513513513, F1S: 0.9850445303310, }, \
 {name: "On", TP: 18, FN: 37, FP: 7, TN: 6002, TPR: 0.3272727272727, TNR: 0.9988350807122, PPV: 0.72, NPV: 0.9938731578075, FNR: 0.6727272727272, FPR: 0.0011649192877, FDR: 0.28, FOR: 0.0061268421924, F1S: 0.45, }, \
 {name: "Off", TP: 1, FN: 37, FP: 3, TN: 6023, TPR: 0.0263157894736, TNR: 0.9995021573182, PPV: 0.25, NPV: 0.9938943894389, FNR: 0.9736842105263, FPR: 0.0004978426817, FDR: 0.75, FOR: 0.0061056105610, F1S: 0.0476190476190, }, \
 {name: "Dimmer", TP: 2, FN: 46, FP: 4, TN: 6012, TPR: 0.0416666666666, TNR: 0.9993351063829, PPV: 0.3333333333333, NPV: 0.9924067348960, FNR: 0.9583333333333, FPR: 0.0006648936170, FDR: 0.6666666666666, FOR: 0.0075932651039, F1S: 0.0740740740740, }, \
 {name: "Lighter", TP: 1, FN: 47, FP: 1, TN: 6015, TPR: 0.0208333333333, TNR: 0.9998337765957, PPV: 0.5, NPV: 0.9922467832398, FNR: 0.9791666666666, FPR: 0.0001662234042, FDR: 0.5, FOR: 0.0077532167601, F1S: 0.04, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x1c, 0x8b, 0xd8, 0xfd, 0xf1, 0x49, 0x4e, 0x4f, 0xb5, 0x56, 0x6f, 0x84, 0x28, 0x7d, 0x15, 0x95}

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
