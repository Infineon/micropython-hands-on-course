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

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "model.h"

// Working memory
static int8_t _buffer[8800];
static int8_t _state[2608];

// Parameters
static const uint32_t _K5[] = {
    0xbbb17a28, 0xbc54c0d1, 0x3c794d7d, 0x3b9004e0, 0x3b7c3d9a, 0xbb9cf1f4, 0xbaee26a3, 0xbc1a81b9, 
    0x3c81987a, 0x3ae0557f, 0x3b174cba, 0xbba0006e, 0x3ae6f58a, 0xbc4f50a3, 0x3c3e7e9f, 0xbbec7a56, 
    0x3ad0acf1, 0xbb81095d, 0xba34ddaa, 0x3aa71dda, 0xbae89490, 0xbba87813, 0x3b191d34, 0xbb08ffc9, 
    0x3b6ba29b, 0x39b77eb3, 0xbb4925cf, 0xbbfdf17c, 0xba12b0df, 0xbc168825, 0x3c111dfd, 0xb9d3f4ff, 
    0xbbc0cbd5, 0xbb961e6a, 0x3b552c8f, 0x3bf73d10, 0x3bb4b889, 0x3b01f7b8, 0x3bcb3112, 0xba9fac72, 
    0x3b732d80, 0x3c232364, 0x3b8e689f, 0x3b3aa41e, 0x3c22f9dc, 0xbbc1833d, 0xbc0081f6, 0xb98e2810, 
    0x3c0bdd57, 0xbad23bef, 0x3c3eacb8, 0xba09e7eb, 0xbbd109a5, 0xbb0a7895, 0xbc29612e, 0x3b38eeec, 
    0xbb08ed60, 0xbb071924, 0x3c8034de, 0xbc0e9407, 0x39cbcd2a, 0xbbd0b4f3, 0x3b535c3d, 0xbbd6d4eb, 
    0x3c14af13, 0xb95d3106, 0x3bae086b, 0x3b0c17bb, 0xbb689bdc, 0x3b84785d, 0xbcc3b072, 0x3c280ca3, 
    0x3af7f093, 0xbb5c8792, 0xbc2622a0, 0x3b08be10, 0xba5e5123, 0x3aeab4c5, 0x3c1b4e6c, 0xbbdf578c, 
    0xbba47bbf, 0xbb1d42d8, 0x3a99656a, 0x3acd19f4, 0x3ba61992, 0xbc0f1fed, 0xbbe70593, 0x3be85b34, 
    0x3b88059f, 0x3c278fe4, 0x3d719ac2, 0x3a8115b4, 0x3bcdd1ef, 0x3b84d31a, 0x3b105105, 0xbc08566f, 
    0x3d515923, 0x3c2d94c8, 0x3afb9bf9, 0x3c0a106e, 0xbbd476ea, 0xbbf332b1, 0x3d851e71, 0x3c0978b9, 
    0xbc4a2b30, 0xba8b5b35, 0x3ad483d0, 0x3c1fafc7, 0xbbe20f1b, 0xbbee2b4c, 0x3b20a25b, 0xbaf437aa, 
    0x3b6b9253, 0xb8299795, 0xbb97b6ac, 0xbc0ae4b1, 0xba3520d4, 0x3b34544e, 0x3b22006d, 0xbba0870b, 
    0x3ab51fac, 0xbbfa9da2, 0x3afa9129, 0xba08a93a, 0x3ba98284, 0x3acfac5d, 0xbb6c1803, 0x3bc42a23, 
    0x3b0b5e47, 0xbb9227bb, 0xbc007ab7, 0xb8df32a0, 0xbae2b80b, 0x3b62b5c6, 0x3b58eccb, 0xbbd5f8a1, 
    0xbbb534fc, 0xbb8092bc, 0x3aa28ab7, 0x3bed2de2, 0xba31b129, 0xbaab987d, 0x3b83caa6, 0xbbdefec8, 
    0x3ba2ae6a, 0xbc2284e0, 0xbb7e6b15, 0xbb6e02d1, 0xbac42e8b, 0xba3d0bc7, 0x3b165c30, 0xbc179f1b, 
    0xbb831257, 0xbb061105, 0xbb26c6fa, 0xb9acbd72, 0xbba993e4, 0xbc59cdda, 0xbb1ec758, 0x3bb50ced, 
    0x3c190167, 0xbc4c6aff, 0xbb1ead95, 0x3b7ebe54, 0x3c19956e, 0x3c161eca, 0xbbb34c02, 0x3c8a64b2, 
    0xbbc8cf3a, 0xbc12f199, 0xb983fcf2, 0xbb80d3ee, 0x3c70ee59, 0xbbe34ff0, 0xbb839771, 0x3aa3d7b4, 
    0xb775e78a, 0xbbcaacef, 0xbbd56cad, 0xbc8430a0, 0x3bd5a7a7, 0xbb6a10ec, 0xbc5de5f0, 0xbb43a378, 
    0x3bfc6068, 0x3bd21fe6, 0xbb1aaa62, 0xbbaa2220, 0xbc28a942, 0x3c00ed6a, 0x3c4968e6, 0x3ba4cbfc, 
    0x3b68809f, 0x3be9fecf, 0xbb89c75a, 0xbc393434, 0xbc2a50f7, 0xba8af1a5, 0x3d230767, 0xbc378502, 
    0x3c8aca14, 0xbc6b5539, 0xbb825406, 0x3bd07c57, 0x3d0ae84c, 0xb9904765, 0x3c14ad8a, 0x3c1aa927, 
    0xba7914c2, 0x3b2561f5, 0x3ceed6dd, 0xbb20b933, 0x3c7e7667, 0x3bffffaf, 0x3bd18186, 0xba45ab35, 
    0xbc141b9a, 0x3b8f9f6e, 0x3b6f1553, 0x3ba94a65, 0x3aa64751, 0xbb04e428, 0xbc13054a, 0x3b6928c4, 
    0x3b856343, 0x3bc3ea30, 0x38c99ae7, 0xbac38670, 0xbc3233f1, 0x3b89b959, 0x3a5ee77b, 0x3b404d22, 
    0xbaebb84b, 0x3b603a43, 0xbc0c174b, 0xb9ed41d8, 0xbb09e670, 0xbc0f71f4, 0x3b7abbe5, 0x3a548f28, 
    0xbc1ea5a2, 0xb9d00a28, 0xbb529996, 0xbc105867, 0xba0b7ebc, 0x389b5838, 0xbc40b396, 0xba822ba2, 
    0xbb9c54ca, 0x3a3cbcbb, 0x3b3905d5, 0x3afa4b06, 0xbce9809c, 0xbbf39215, 0xbb07229d, 0xba59f1c2, 
    0x39bb60bd, 0x3b9ab830, 0xbcad4d4e, 0xbb01a303, 0xbb33ae80, 0x3c0a1039, 0x3a4d3a38, 0xbbadc8be, 
    0xbc8a35d9, 0xbbdb53c0, 0xbb26a649, 0x3b5bbcab, 0xbc057ce8, 0xbc0fc779, 0xbb56419e, 0x3bfa2e8b, 
    0xbb922a44, 0x3b79675f, 0xbc0dbd68, 0x3b12dc5a, 0xbbca3b4a, 0x3beceff0, 0xbbdb2b47, 0xb90d8209, 
    0xbbbf98c5, 0x3a150a04, 0xbb862471, 0x3c3729f9, 0xbb5749bc, 0x39e82a70, 0xbab45d3e, 0x3b4850a5
};

static const uint32_t _K8[] = {
    0xbf0a520c, 0xbd753776, 0xbda358ac, 0xbc865b7e, 0xbe310f80, 0xbf008800, 0xbcdd19bc, 0xbc34417c, 
    0xbe52486c, 0xbdacb9a8, 0xbec4c5c4, 0xbed8b40c, 0x3eb0c78a, 0x3ed1dbfc, 0xbe723d15, 0xbddae4ce
};

static const uint32_t _K12[] = {
    0xbd401ffb, 0xbd270c19, 0x3e219d95, 0x3e25b50b, 0x3d914358, 0xbe0fa6a7, 0xbe393505, 0x3e345e73, 
    0x3e8c8579, 0x3e75a001, 0x3d38ec88, 0x3a9c931c, 0x3bbe1605, 0xbd3605b9, 0xbd9ceea0, 0x3db5cca7, 
    0xbdf32aa1, 0x3dc75eb5, 0x3d68e3ee, 0x3e247a13, 0xbecd5a86, 0xbe016fd6, 0xbe3326e5, 0x3cf232fa, 
    0xbb9176ee, 0x3d8427d8, 0x3f1363b9, 0x3ea943be, 0x3e687e42, 0xbe7e2e78, 0xbdf9d5f5, 0x3c7dfd3b, 
    0xbeb64592, 0xbca295a5, 0xbe22dbff, 0x3d315757, 0xbeb1722c, 0xbe831c53, 0xbef77609, 0xbe22d3c6, 
    0xbd9bfe7b, 0xbe3ae43c, 0xbd4b9881, 0xbf02fc30, 0xbeedcc23, 0xbda58c8e, 0xbf2936d8, 0xbe9e3f41, 
    0xbe87d761, 0xbb7f8d2d, 0xbd20016f, 0x3d2062b6, 0xbc830f32, 0xbe55df99, 0x3d2c1a31, 0xbe3b002a, 
    0xbdd582ee, 0xbe0838ae, 0x3db59a3f, 0xbc6e64da, 0x3e61031c, 0xbc95ffa9, 0x3e213fbe, 0xbe947ef5, 
    0xbdccf09c, 0x3d0c2e43, 0x3e88573e, 0xbd9b9358, 0xbd76fccc, 0xbe37ce39, 0xbd997b06, 0x3c8d4c4d, 
    0xbe143a80, 0xbe015629, 0xbd037184, 0xbb8246ba, 0xbe494b94, 0x3e0b3622, 0x3caff607, 0x3d609230, 
    0xbea4da20, 0xbd9a8ea4, 0xbe266832, 0xbe144277, 0xbdd689c2, 0xbee7a621, 0x3dc7b6cc, 0x3de48659, 
    0x3d82903b, 0xbedc5435, 0x3da98973, 0x3ed2a43c, 0xbdf0d6e0, 0x3d806428, 0x3ce03963, 0xbe8e1678, 
    0xbe4aabdd, 0xbe5768db, 0xbe22f350, 0xbed40173, 0xbe1bf07a, 0xbd5877e8, 0x3e8d9589, 0xbf0de40a, 
    0xbe59b3db, 0xbe449f9e, 0xbe682241, 0xbc78f8cd, 0xbdf414e3, 0x3ec5cafe, 0xbde7db2e, 0xbed2e49c, 
    0xbe513e45, 0xbdc0cfe1, 0xbee1a98a, 0xb8b50935, 0x3e0085db, 0xbddeea43, 0x3bea75c7, 0x3d102d9d, 
    0xbe4f897a, 0xbebd91f2, 0xbed4574b, 0xbdb11c50, 0x3dc4d073, 0x3e34dbbd, 0x3d8d0e28, 0x3cb758d2, 
    0x3d88c903, 0x3d001419, 0x3dbe0118, 0xbda0fc90, 0xbe6b8e31, 0xbe1fdeab, 0xbe5d3f79, 0x3e56ff09, 
    0xbee7476c, 0x3d211e86, 0xbe96cd6b, 0xbe9ae972, 0x3e29b97d, 0x3e0c9cab, 0x3ea147be, 0x3ca9ef19, 
    0xbea3f68e, 0xbd7bc4a8, 0xbeb94e92, 0x3ddd80c4, 0x3e1cdc22, 0x3ddd0e1d, 0xbd81a468, 0xbd128e92, 
    0x3dd07d96, 0x3e5acb01, 0xbdb5ff9e, 0xbe3c2aa7, 0xbc5cc6f2, 0x3df99918, 0x3e2e5208, 0xbda77507, 
    0xbea53240, 0x3e3265a7, 0xbe1d4c3f, 0x3e9145b5, 0xbea2b608, 0x3b6e61e0, 0x3ebb9feb, 0xbb954b73, 
    0x3e3aeb66, 0x3e39371b, 0x3ec82590, 0xbe860dae, 0x3cb2b866, 0x3d6f33bc, 0xbb7be14c, 0xbd264af9, 
    0xbf04f357, 0xbf351351, 0xbdaf10e3, 0xbe2f508f, 0xbf0b5ac0, 0x3e35377a, 0xbe309820, 0xbdbaf041, 
    0xbc56198b, 0xbe3d2b26, 0xbedadc74, 0xbe523f5d, 0x3cbb8ce6, 0xbe9383f9, 0x3df1082c, 0xbc92f6ea, 
    0x3e4bf07a, 0xbe9c8ef3, 0xbe65353a, 0xbe288a9e, 0xbd99d442, 0x3e4e9eea, 0x3d63c910, 0xbdcd231d, 
    0xbe72648c, 0xbde20694, 0xbed9cd19, 0xbd56a442, 0x3dc8bc8b, 0xbe453ebf, 0xbcaa288b, 0x3d6c5fe5, 
    0x3e77aa96, 0xbea31c86, 0x3c1b0bbe, 0xbe3954b9, 0xbd5bdeaa, 0x3c6dd620, 0xbd8cf85a, 0x3c997a92, 
    0x3e031170, 0x3ce8c5fc, 0x3e0822e3, 0x3d40881e, 0x3d5578cd, 0xbd0d916c, 0x3e3dc5f4, 0x3e3ec4e5, 
    0x3e49c706, 0xbe2bc0fd, 0xbe801f07, 0x3d9a1f05, 0x3e168015, 0xbe9a03f8, 0x3df41d5d, 0xbe85d2c4, 
    0xbe3f61a5, 0xbea08061, 0xbe37438b, 0xbd0a33e5, 0xbc2837b5, 0xbe89e75c, 0xbe3ce7a6, 0xbd602635, 
    0x3c941f4f, 0xbe193e55, 0xbe4616ed, 0x3df1e252, 0xbe7005ac, 0x3e09a5d8, 0xbd68486f, 0xbedc20ae, 
    0x3dd15d78, 0xbe5e3c1c, 0xbd71cc07, 0xbe0ddfa9, 0xbccaca7d, 0xbeaf854c, 0xbd355408, 0x3e3b1a63, 
    0x3e1ff400, 0xbdc23a29, 0x3de6866f, 0xbdfb3267, 0xbe7799ab, 0xbd9384b6, 0xbc89c1b9, 0xbeac8dc4, 
    0x3e724a42, 0x3d74230f, 0xbd566877, 0x3dd8ff04, 0xbda7d334, 0xbea9c34d, 0x3de6e645, 0x3e23b2d2, 
    0x3db9ccfa, 0x3e0a0b12, 0xbd89f5d3, 0x3c5f8de5, 0x3defcbfb, 0x3e1a37be, 0x3d707e4f, 0xbe707a79, 
    0xbd94b00e, 0xbdbb43ce, 0xbd2bdcca, 0x3d8ff941, 0xbe447634, 0x3acc3695, 0xbe0893fd, 0x3e2b3a24, 
    0xbe9b8f44, 0x3c60d9ca, 0xbf048147, 0xbeb41ba5, 0xbf46ab4e, 0xbf80c224, 0xbed90164, 0xbe886c11, 
    0xbf029dd8, 0xbed142e7, 0xbe923f17, 0xbf0e1b44, 0xbf156c33, 0xbf0e64bf, 0xbee6f946, 0xbf08a015, 
    0x3e0a29a2, 0x3df4adc2, 0xbbba8b32, 0x3d217fa2, 0x3e12166b, 0x3f07f494, 0xbb0ba402, 0x3e7c188c, 
    0x3e9b4a10, 0xbe948069, 0x3ec31c19, 0x3d13a065, 0x3e42ae2f, 0xbdd017d7, 0x3d715e1c, 0x3e3fba2f, 
    0xbb863ac7, 0x3eca5d58, 0xbc8de1b6, 0x3e46e18f, 0x3ec8a9ca, 0x3e2620b2, 0x3e44538a, 0x3e13833c, 
    0x3e98204e, 0x3d9bfa86, 0x3e2ef77b, 0xbc006dc3, 0x3c9fe309, 0xbe42dc1b, 0x3da4651b, 0x3a9f3eca, 
    0x3ec5e91d, 0x3e8da695, 0x3e1bc0dd, 0x3e8996ed, 0x3e73aa80, 0x3d584a9b, 0x3ec29fe2, 0x3e806f6b, 
    0xbd373a28, 0x3d1c03cf, 0x3ebcd463, 0x3e739b61, 0x3e4c1e48, 0x3e728725, 0x3dfb93a9, 0x3f084c86, 
    0xbcec4de7, 0x3e953fb8, 0x3d6db97d, 0xbdf49144, 0x3d4da633, 0x3e352f07, 0xbdbd8b65, 0xbe1e7c2e, 
    0xbe27e5ae, 0xbd960900, 0x3d56babf, 0x3cd1618b, 0xbdbd9262, 0xbdc4df60, 0xbeb36028, 0xbe49350b, 
    0xbe610c72, 0xbe8dccff, 0xbec0c506, 0xbe16fd97, 0xbec05e4b, 0x3d9edb65, 0xbe841d0b, 0xbebee53a, 
    0xbcbfa80d, 0xbd9fd3d6, 0xbea2f1ae, 0x3d709c80, 0xbe858539, 0xbeab9e0f, 0xbdb37f9d, 0xbeb5410d, 
    0xbdc1fdc7, 0x3d60e58c, 0x3d2c37f0, 0x3d162c4d, 0x3cce51cf, 0xbdc5866d, 0xbc0f18f1, 0x3d41a64a, 
    0x3d2d62f4, 0xbe2bd1df, 0xbda7caba, 0x3e235195, 0xbea67b6f, 0x3bd50fe6, 0xbde63202, 0xbdb3a6fb, 
    0xbc2793e1, 0xbd54e1a4, 0x3d9da491, 0x3d45a119, 0xbc24c71a, 0xbe054aa1, 0xbc8a71c1, 0x3d99af2f, 
    0xbd9c8a5c, 0x3e48a527, 0x3c96726c, 0xbda2423f, 0xbde42fdc, 0x3d08eb65, 0xbd968c99, 0xbd8ad56d, 
    0xbdeb8495, 0x3d4abda2, 0x3d303e95, 0xbd77f93c, 0xbd099aab, 0xbdfdeba6, 0xbd14bd49, 0x3e1c7e35, 
    0xbe0dce9f, 0xbe0e6952, 0x3d0de768, 0xbdbc2f55, 0xbe810ea6, 0x3da9c553, 0xbe8bcd9d, 0xbe4c3451, 
    0xbdc1c40d, 0x3daf7718, 0xbd7c70d4, 0xbe4db36a, 0x3def5fcb, 0xbe7073a1, 0xbd04ad89, 0xbcc2fe34, 
    0x3e70b5ba, 0xbe5d7bc0, 0xbd1977d6, 0x3d180daa, 0x3d83b8f8, 0x3dd12a59, 0x3e1cd13d, 0x3d66e90b, 
    0xbc2bd2b3, 0x3e81e7e3, 0x3d90d2ed, 0x3e8cfd55, 0xbd9266fa, 0x3bfffbd1, 0x3e23041a, 0x3d831aa3, 
    0xbcd930f3, 0xbe7b899a, 0x3ddd0b12, 0xbdf1dc87, 0x3d1f5621, 0xbd1626db, 0xbe9a60e2, 0x3e2eee54, 
    0xbe93e317, 0xbd316a22, 0xbdfa6a70, 0xbf1d2ebb, 0xbe7906ff, 0x3d5ea645, 0xbe857834, 0xbe80dbc6, 
    0x3dfd0d77, 0xbef60844, 0xbeb19592, 0x3cee6228, 0xbe4c5e26, 0xbd0ae485, 0xbe2f3d79, 0xbe9c6720, 
    0x3dabe13d, 0x3b6a525d, 0xbb83fb3d, 0xbd569ec5, 0x3cfb1067, 0xbea5a00d, 0xbd531049, 0x3d611645, 
    0x3de88b3c, 0xbdc99534, 0x3d085650, 0xbeac921d, 0xbd27cdc9, 0xbda45ca9, 0x3dadfc64, 0xbcc34fa9, 
    0x3dcb4ae8, 0xbc9fdbfd, 0x3d49302e, 0xbe181b2a, 0xbb3f4f96, 0xbebd4eb5, 0x3c312f7f, 0xbe137400, 
    0x3dc94c70, 0xbe01b254, 0x3d31e3df, 0xbe20e9d6, 0x3c439e71, 0xbc2aad98, 0x3df1548f, 0x3d91e008, 
    0x3d176ceb, 0xbd3bbffa, 0x3e28ec0e, 0xbe023158, 0x3e4f99f7, 0xbe8526b8, 0x3dd16a66, 0x3d816b88, 
    0x3de61b9a, 0xbd1b26d2, 0x3e6138fd, 0xbe86ac25, 0xbd538ab6, 0x3dbf64a7, 0x3dd3f88f, 0x3e0f8472, 
    0x3d3582a2, 0x3dc6a7c6, 0x3d838615, 0xbd0c15de, 0x3e09231e, 0xbccb11fd, 0xbe3cccc7, 0x3d66cab6, 
    0x3e2af9d5, 0x3e3fdaeb, 0x3bd451b1, 0x3da53efa, 0xbcc53109, 0x3df865ad, 0x3e1ddd31, 0xbde005d7, 
    0xbd8acbba, 0xbe8b22c2, 0x3d35816d, 0xbd1ea2d5, 0x3c6bc6d5, 0x3dd2ac95, 0xbdbafec0, 0xbcd7f46a, 
    0x3d5fcd95, 0xbdb382b1, 0x3dc25835, 0x3ddbea73, 0x3e2bae11, 0xbd230f2c, 0x3cdf1f08, 0x3d448be5, 
    0xbbc4f10a, 0x3d81408e, 0x3d857b7c, 0x3c23b9df, 0x3df088a6, 0x3e45c2ca, 0x3d51fc1e, 0xbce19222, 
    0x3e20924f, 0xbdbfe119, 0x3e029fcf, 0x3d163b3b, 0x3d0034c1, 0x3e20d088, 0x3d838f46, 0x3d99ca5b, 
    0x3d6561c9, 0x3e29ed63, 0xbde8b930, 0x3dfdcc8e, 0xbe962d87, 0xbdaf474b, 0xbeb44185, 0xbe2c49b0, 
    0xbd8690d8, 0xbc383863, 0x3e5ad899, 0xbd80b711, 0xbc8ea6e3, 0x3ba6cd84, 0xbd28d0c0, 0xbd5b9424, 
    0x3d98108e, 0xbe06eb5f, 0xbe4917e3, 0x3cb7f6c4, 0xbe618e11, 0xbea5e04e, 0xbe829584, 0xbde37c89, 
    0x3de852f9, 0xbe16caea, 0xbe9eb9b0, 0xbd295dd4, 0xbe36f673, 0xbe73b862, 0xbe3b856a, 0xbe62f3f0, 
    0x3e88a8dd, 0xbe6dad54, 0xbd55a84c, 0x3e5a5652, 0xbddc1c38, 0xbe531f80, 0xbd26b2d9, 0x3cac9a0b, 
    0x3bf47927, 0x3df4f438, 0x3e6cf54c, 0x3df5a361, 0xbd713876, 0xbe3f5e78, 0xbe7bf9e3, 0xbddd30ad, 
    0xbe81a0de, 0xbd3912be, 0xbc7b346d, 0xbf2d3aa2, 0xbd7875ac, 0xbbaa0a90, 0x3d986cdd, 0xbdee4674, 
    0x3dc4fd03, 0xbec267dd, 0xbd8aabb6, 0x3d3b964d, 0xbd340cd9, 0xbce823b4, 0x3d97319a, 0xbde20239, 
    0xbe0a183c, 0x3d185bb5, 0x3d072d6c, 0xbec01609, 0xbcce27c7, 0xbc9a689f, 0xbd32603a, 0xbcc87274, 
    0x3dc6332e, 0xbe54cb4f, 0xbde71d95, 0x3d093404, 0x3cf52d65, 0xbdbcafda, 0x3d4d8874, 0xbd8a91ff, 
    0xbe1571b6, 0xbda72260, 0xba79739a, 0xbeac7262, 0xbdfbf363, 0x3d814ac9, 0xbd0fac90, 0xbc8297c5, 
    0xbba2992b, 0xbe7e87e4, 0xbd0c732c, 0x3d9d32e3, 0x3d4bf85b, 0xbddff68b, 0x3cbf8131, 0xbdbabe55, 
    0x3db63186, 0xbe205d15, 0x3e95b707, 0xbc38e7f5, 0xbdf45d39, 0x3e3e0a46, 0xbdedf864, 0xbd0ea797, 
    0xbea1e3a1, 0x3da9bbd6, 0xbe4037e4, 0x3eb9b58c, 0x3dc45e9c, 0xbec502b0, 0x3d6a7cd2, 0xbe629f28, 
    0xbe518001, 0x3dd80797, 0x3e920d63, 0xbe3b2689, 0x3d7bb40e, 0x3ebe5f9b, 0xbdd8eda4, 0x3da3805a, 
    0x3e325b80, 0xbdac7a91, 0xbdaaa9fc, 0x3eb193e5, 0xbf0599bd, 0x3e86c644, 0xbe6fc979, 0xbdbb7ef2, 
    0xbe36a707, 0x3d7325ab, 0xbd5cc004, 0x3d3c262a, 0x3e415125, 0x3dc86a03, 0xbd85e616, 0xbb151d2f, 
    0x3e42a04b, 0x3cb46a1b, 0x3d93a0de, 0x3e1f3fed, 0x3ce1c21c, 0xbd85af78, 0x3e539aa4, 0xbe864055, 
    0xbe4a5f72, 0xbe943095, 0xbd16af72, 0x3d926906, 0xbc9cc5f9, 0x3cc85334, 0xbe5a5a9b, 0xbdcc27ad, 
    0xbbf5696b, 0x3da27a82, 0xbe465234, 0x3d884878, 0x3c8a4914, 0xbe817657, 0x3d95809e, 0x3dcd6268, 
    0xbe3f96e2, 0xbc7c5443, 0xbe2dfb09, 0xbdd6879c, 0x3dccddbf, 0xbcf77db3, 0xbe046f6d, 0xbe7e8dc4, 
    0xbd64d775, 0xbd9d8299, 0x3d4878bc, 0x3cdcc09b, 0xbe08f87e, 0x3d3ef4e7, 0xbe4f60ea, 0xbd437bfd, 
    0xbd6c46b7, 0xbdadb002, 0x3bf27ccb, 0xbe9bf9bb, 0x3e0487bf, 0xbe60aa46, 0x3de91dad, 0xbec08b74, 
    0x3e404a8c, 0xbc831f9e, 0x3d8e3c3b, 0xbe05d230, 0xbde581e1, 0xbcde22e6, 0xbe4dd2da, 0xbe8669b4
};

static const uint32_t _K15[] = {
    0x3f8aef34, 0x3f115d98, 0x3f568076, 0x3eb86e10, 0x3f31e45b, 0x3e6d70b8, 0x3eeeca8c, 0x3e89458a, 
    0x3e46ee52, 0x3f35999a, 0xbe8eef52, 0xbf6d7dc4, 0x3f5b0da5, 0x3f61d0ed, 0x3e26d3a0, 0x3f178c7e
};

static const uint32_t _K19[] = {
    0xbf70e8d7, 0xbdaf8e0c, 0x3f336919, 0x3e0450bd, 0xbeed3d23, 0xbec257ac, 0xbf23114f, 0x3ec11af5, 
    0xbe17b3d0, 0xbd5cd2fa, 0xbcbbfa8e, 0x3d8aae6e, 0xbf2c3f3b, 0x3f2677ef, 0x3ecb99ae, 0xbd5ed0bf, 
    0x3f7bbef7, 0xbe852b40, 0xbed7f405, 0x3f664af1, 0xbe04b29a, 0xbe896864, 0x3ed66d61, 0x3f526ea5, 
    0xbf8b50d1, 0x3fb3d9d8, 0xbcd1c201, 0xbf73aee7, 0xbff2ad59, 0x3e1fbd09, 0x3fa7adf6, 0xbd13a874, 
    0xbf48c60b, 0x3f074145, 0x3b996e98, 0x3bc60239, 0xbf684247, 0xbf88b88a, 0xbeb6f4b3, 0xbfb793cb, 
    0xbeadf3b4, 0x3f950b4c, 0xbc866287, 0x3eb7f482, 0xbfb136f9, 0x3fd86b85, 0x3f0dbd8d, 0xbebbfded, 
    0xbe10ac4d, 0xbfb79b76, 0xbfc29c01, 0xbcb2000e, 0x3ea96636, 0x3e8ad0b6, 0xbecac71f, 0x3da122bd, 
    0xbf9703e7, 0xbf6d3f33, 0x3c93196a, 0xbf76f9c4, 0xbecf3b0f, 0x3ebc8b34, 0xbd782a47, 0x3f05f8ee, 
    0x3ed9698e, 0xbf420bec, 0xbef2423c, 0xbf18de60, 0x3daab590, 0xbeaeb2c6, 0xbef555e4, 0xbf2afd1e, 
    0xbc9f958f, 0x3f0a5c25, 0xbd133fac, 0xbee4e665, 0xbd2dca6b, 0x3f5cb26f, 0xbea10b8e, 0x3de3f9c7, 
    0x3f92d41f, 0xbef12f1d, 0xbf956b45, 0xbf313575, 0x3e6a281a, 0xbec95c06, 0xbf15b98c, 0x3be43784, 
    0xbe8f5ab7, 0xbf09c463, 0x3d825a10, 0xbf0f203b, 0xbf01cae8, 0x3ecf84e9, 0xbe46db14, 0x3e2218c1, 
    0xbe07276b, 0xbcc4219e, 0xbe34785f, 0xbc8260bd, 0x3e8baf07, 0x3f8675d9, 0x3e455369, 0xbf07ce23, 
    0xbf3efd3c, 0xbefe1f28, 0xbf25ffdf, 0xbee6ff92, 0xbf97c3f6, 0xbf266e0f, 0xbe99d1eb, 0x3f0d5a6d, 
    0xbf19054e, 0x3f0a3c62, 0xbe381dbb, 0xbed852b3, 0x3e61b8f7, 0x3f453d77, 0x3ed5470a, 0xbf3c222f, 
    0xbf9c83a4, 0xbd6d6588, 0xbf1b79bc, 0xbe9d15c8, 0xbd8ed275, 0xbe0372e6, 0xbea30db0, 0x3e9ea978, 
    0x3f53979e, 0x3e1318f2, 0xbd80252a, 0xbf3e5593, 0xbe23b0b5, 0xbe694a42, 0xbe336b58, 0x3f0e7c5f, 
    0xbf592b55, 0x3f386434, 0xbf116fc8, 0xbf033d2f, 0xbe8d2997, 0x3cdcfe0d, 0xbf1aec5c, 0x3fcac31e, 
    0xbe1e2e8b, 0xbe8e8462, 0x3f2a2961, 0xbf136d8b, 0x3f13c302, 0x3e368717, 0x3e987e66, 0x3db771c2, 
    0xbe811240, 0x3d7cf2e0, 0xbdb9e784, 0x3e593daf, 0x3d5b2cea, 0x3f9cc511, 0x3e9396dd, 0x3f372964, 
    0xbc8a2862, 0xbdb49541, 0xbda582a2, 0x3efc19a3, 0x3e319df5, 0x3e110c10, 0x3e8a4d9d, 0x3f0205da, 
    0x3e8e3cb6, 0x3f78f224, 0x3d06c814, 0x3dbf7000, 0xbdb62a5e, 0x3f22719d, 0x3e0c1de3, 0x3eb70ec0, 
    0xbd0a8a46, 0xbec852ce, 0x3f14f894, 0xbeb2b6c0, 0xbe6fc49f, 0x3d8228d8, 0xbdf4e393, 0xbeb80fe5, 
    0x3df1747a, 0x3eb373a6, 0xbed7110b, 0x3edf1d26, 0xbe0f1eb1, 0x3f1e45c1, 0x3ddcc826, 0x3cb72449, 
    0xbf829db5, 0xbf3e4069, 0xbf89ed45, 0xbe98445b, 0xbf12a741, 0x3f829a2d, 0x3fffdf3f, 0xbf609790, 
    0xbef7b8d5, 0x3e8eb253, 0xbece0902, 0x3f035174, 0xbe0075ca, 0xbdfddf8e, 0x3da78ebc, 0x400328c4, 
    0x3e248a41, 0x3f09b0cc, 0xbf1d3aeb, 0x40143927, 0xbe6257b7, 0x3f29188d, 0xbf8454c2, 0x3f590f74, 
    0xbec5ce7b, 0x3fa25d92, 0xbff26de0, 0x3f841c27, 0xbfcf07f6, 0xbfaf5f6b, 0x3ff60582, 0xbf5b2af1, 
    0xbfabf2bf, 0xbf09275b, 0x3f37923c, 0x3f43f2a8, 0x3f2efe6a, 0x3e98b21c, 0xbf618d7c, 0xbffdb5c1, 
    0x3fba8edf, 0xbf8b4cc5, 0xbfcb7184, 0xbfac81a0, 0xbf3f3b46, 0xbead33d4, 0xbd8a2fbe, 0x3e70ad6a, 
    0x3ecd21c2, 0xbf67fbd4, 0xbf99ccee, 0xbed816da, 0xbf6a61c5, 0x3eab859f, 0x3df6a167, 0x3e8dcee9, 
    0xbf12dbdd, 0xbf0df218, 0x3d3b695d, 0xbda1820e, 0xbf92f535, 0xbfd7bf8a, 0x400fe6fe, 0x3d43b0f5, 
    0x3ed85320, 0xbe6a9ea7, 0x3f18637f, 0x3ed281bb, 0xbe2675a1, 0xbed512d3, 0x3e3730be, 0x3a83a90e, 
    0xbe80f918, 0x3f56fd3d, 0xbec1bc78, 0xbe8bf916, 0x3edb1723, 0xbdf3e5ab, 0xbe9c5185, 0xbeffba5e, 
    0x3e74a73e, 0x3f611315, 0x3fc31cdb, 0x3f8c4e47, 0x3f2f31f1, 0x3eadf253, 0x3caac529, 0xbea7ae23, 
    0xbe88674c, 0x3f71c2e1, 0x3f94a24c, 0x3f603e62, 0x3fc53028, 0x3f2329b6, 0xbf98137c, 0x3f9fa754, 
    0xbec7422d, 0xbf17f33b, 0x3fc1de50, 0xbf9b103f, 0x3d859740, 0xbf28cc16, 0x3e1a3932, 0xbf13a323, 
    0x3ed84ac8, 0xbf1bba77, 0xbf07751d, 0x3e505428, 0xbe720e3a, 0xbdf47293, 0xbe81b236, 0xbe589fa2, 
    0x3f86a044, 0x3ddcde14, 0xbf820f60, 0x3e8ea361, 0x3ef03579, 0xbec16eba, 0xbef6bcdf, 0x3f10cb25, 
    0x3e5467cb, 0x3e9ee781, 0xbee1b437, 0xbbb9f5f2, 0xbe3de891, 0x3c90219f, 0x3d5f2f13, 0xbfd079e2, 
    0xbee95b6a, 0x3fc11782, 0x3f0f200a, 0xbe0c6e28, 0x3f5e6281, 0xbf42df0d, 0xbecda506, 0xbfd82fec, 
    0x3f12ad0f, 0x3e2e55af, 0xbf58610e, 0xbeef9d39, 0xbd19ea3a, 0x3ead47f3, 0x3e94cc44, 0xbf73b999, 
    0x3d3207bc, 0x3f57f806, 0xbf9dfd36, 0x3e7f1b6b, 0x3f92a1e0, 0x3f13a45d, 0x3db2e50d, 0xbed266e9, 
    0x3f386016, 0xbf9a8dff, 0xbf762dd1, 0xbf9fe4f0, 0x3e88a225, 0xbe9fd5e7, 0xbf508b80, 0x3f68d420, 
    0xbf2ecc5d, 0xbe65715e, 0xbce327d0, 0xbea01988, 0xbf3732d1, 0x3f6aae75, 0x3eb1e773, 0xbf678b7e, 
    0x3de6439d, 0x3f23c023, 0xbe28fe8b, 0x3da3ecc8, 0xbf3aa5fc, 0xbf4e8d37, 0x3e8611f6, 0xbe04e88d, 
    0x3fedaf7c, 0x3981caf5, 0xbfea244c, 0x3e8b4f60, 0x402708f8, 0x3ef5736f, 0xbf819b54, 0x3f0f9a62, 
    0xbe466a35, 0xbe3ad2c1, 0xbf93f55a, 0xbf51458a, 0xbed3fb37, 0xbfab041d, 0xbf7e4771, 0x3f73df2b, 
    0xbf1680aa, 0xbfc29a7b, 0xbf1d1b94, 0xbfc4b52c, 0xbecddaba, 0x3ef4e433, 0xbef46d57, 0x3e94d9c3, 
    0xbdad9f03, 0x3d8ea67b, 0x3eaddfd4, 0x3f2837b3, 0xbd71fa5e, 0xbe1a47f4, 0xbf865d24, 0xbee1c653, 
    0xbecfa0a8, 0xbf8ee910, 0x3e2393d1, 0xbf92c3e5, 0xbe11d790, 0xbf575243, 0xbef53f90, 0x3db6fce8, 
    0x3f163715, 0xbe60e479, 0xbcddcbe5, 0xbd16424a, 0xbc45d09a, 0xbe48886e, 0xbf9fb2b9, 0xbdc66431, 
    0xbedf6530, 0xbee43ac1, 0xbdf20363, 0xbfa86e7c, 0x3ec39e3f, 0xbf745047, 0x3eede6ea, 0xbd8e0717, 
    0xbd9e204d, 0x3e89caae, 0x3e6aa4b7, 0x3f4d1fa8, 0x3cf1d8e6, 0x3f17647e, 0xbf6ed0cd, 0xbea499c7, 
    0xbead7a84, 0x3ea7169b, 0xbe890431, 0x3cc554ba, 0x3e110368, 0xbf5d98a0, 0xbf2cd8b3, 0xbf6e4677, 
    0xbe043071, 0x3f25ebc4, 0xbec50a69, 0xbee77e76, 0x3f51892a, 0x3f8d2191, 0xbe867f7b, 0xbf02685a, 
    0x3f39f3e2, 0xbec94683, 0x3dbc072c, 0xbd42c61e, 0x3f07def3, 0xbdeaa791, 0x3fcb32a1, 0xbf2265bb, 
    0x3e7500fe, 0x3dfdfd06, 0x3e9a44a1, 0xbe6bb544, 0x3f13e42d, 0xbe931ef8, 0xbdf33c0b, 0x3e365fb5, 
    0x401d134d, 0x3c81bfb4, 0xbfb3de17, 0x3ed640ed, 0xbf79e89c, 0x3f466a99, 0xbf03ac72, 0x3d16142f, 
    0x3ed25bca, 0x3fb0caaa, 0xbed241f0, 0xbdb84d64, 0x3e573e31, 0xbebac7dc, 0x3d5b9e32, 0xbf17b8bf, 
    0xbf0ba63b, 0x3da693e3, 0xbee38ca5, 0x3cccfd9b, 0xbf5d53aa, 0xbebbcfc1, 0x3fc6beec, 0xbf24543a, 
    0xbf3235bf, 0xbea4ab40, 0xbfa2fd72, 0x3f7aaa11, 0x3f9dfcba, 0x3e4a064a, 0xbeb572ca, 0x3f718fc1, 
    0x3f9e635e, 0x3f552e3a, 0xbffc15b2, 0x3e8738a1, 0x3dcefbae, 0x3ede7394, 0x3e056003, 0x3eb06174, 
    0xbe811949, 0x3fac96d9, 0xbe9c8e9b, 0x3f802c77, 0x3f340586, 0xbedd4694, 0x3f16097c, 0x3c905535, 
    0xbe521913, 0xbfff76a2, 0x3d9d4ece, 0x3f1f9b93, 0xbe928c99, 0x3ebcb297, 0xbefe7109, 0xbfc06448, 
    0xbe1e10a3, 0x3f0e9861, 0xbf4c2b35, 0xbf1d7556, 0x3fa07cb0, 0x3e113f8d, 0xbeeaa803, 0x3f39fd01, 
    0x3f2e8012, 0x3f92bd48, 0xbf50d11a, 0xbfba5c0f, 0xbfc3aa3d, 0xbfd1bc79, 0xc00bafe3, 0xbefa1975, 
    0xbf801fb0, 0x3fe86270, 0xbe3282b3, 0xbfc4ec84, 0xbf53ef60, 0x3f60e4ef, 0x3c205b41, 0xc017b8c0, 
    0x3f7b31bd, 0x3f99e745, 0x3db7ef73, 0xbe87dd03, 0xbe85820a, 0x3ea48024, 0x40214f53, 0x3e6fc44c, 
    0xc0176237, 0x3fb0b9cc, 0x3ef043e1, 0xbf2f2639, 0xc024b210, 0x3ec5fe95, 0x401ab27b, 0xbf4cb71b, 
    0x3f3bb96d, 0xbfa35675, 0xbddcaed7, 0xbfa2e514, 0x3dcab654, 0xbf8acf42, 0xbf22f491, 0xbef1c009, 
    0x3cbfbe4b, 0x3f3e293e, 0x3fa4548b, 0x3f28f9ad, 0xc00fa84b, 0x3f57b373, 0x3eecb0b3, 0xbf0ca374, 
    0x3d578ecd, 0x3f830157, 0xbf06b748, 0x3ed099ff, 0xbf1329c8, 0xbd72ec07, 0x3d7a7491, 0xbd1d667c, 
    0x3d8c943d, 0x3d41fef7, 0x3d6eb6fe, 0xbee05dd4, 0xbf33065c, 0xbf08b239, 0x3f0f1321, 0xbec05107, 
    0xbf0039a5, 0x3e4dcbf3, 0xbdb078a6, 0x3e37181e, 0xbea4143c, 0x3eb2a681, 0xbe7534f6, 0x3ce7f4c5, 
    0xbe914f88, 0x3dd189ff, 0xbb9ff245, 0xbe2f42ca, 0xbe1195e7, 0xbe96d7dd, 0x3ce86393, 0xbef7796b, 
    0xbe8fd4af, 0x3e740a64, 0x3e55548f, 0xbf913276, 0xbf28121c, 0x3e9500a3, 0x3e5feb2d, 0x3cec0f79, 
    0xbf651ad9, 0x3ecbbb9c, 0xbec5489a, 0xbeeb8a94, 0x3f26ed77, 0x3d97c11b, 0x3f9fa326, 0x3e4fc988, 
    0xbf264b9e, 0xbf3cdaf2, 0xbf48db63, 0x3e694e6a, 0x3d1c7ea1, 0xbf17faaf, 0x3e6ca5ec, 0xbe6fbe80, 
    0xbfa7afb7, 0x3f1c0fc6, 0xbf2755c1, 0xbeb4ffbd, 0xbeb6f00c, 0x3ea41622, 0x3e3484a2, 0x3eccfd18, 
    0x3e823c0f, 0x3f278fbb, 0x3f03c956, 0x3d1581a7, 0x3f4409fe, 0xbf589476, 0xbd16154d, 0xbf3ab0c2, 
    0xbe807f53, 0xbe4c4b03, 0xbe87ab81, 0xbf1a628c, 0x3f0a7676, 0x3f9231a1, 0xbe3f33d4, 0x3f6a5424, 
    0xbf5b8b3d, 0xbef20930, 0xbe9349c0, 0xbfa025dc, 0xbfaac3ca, 0x3d49ceef, 0x401af211, 0x3ce083ec, 
    0xbf11e4d2, 0xbea2d53b, 0xbe806195, 0xbf276b5f, 0xbfa50ea9, 0xbeb4faef, 0x3c5530dc, 0xbec36d0b, 
    0xbd9299ed, 0x3dc500fd, 0x3ec83a54, 0xbea97843, 0x3c00a8fb, 0xbcd1509c, 0x3ef233b9, 0xbe0e4dc6, 
    0xbee5a4c5, 0x3ece36a1, 0x3ec9aced, 0x3e12211c, 0x3dc76243, 0x3fb721b6, 0x3e4fa1ae, 0x3eabd30e, 
    0xbe67e2e8, 0xbd0d7564, 0x3e4478cf, 0xbe923340, 0xbde55d05, 0xbea83277, 0xbd3843c2, 0x3d4d42b3, 
    0xbdc0c9f0, 0x3f3487a5, 0x3ef7c38a, 0x3edbe8ff, 0x3da95871, 0x3f886c19, 0xbe305900, 0x3f01c138, 
    0xbc1f8bcb, 0xbea1c517, 0x3e2d16c8, 0xbd6e6665, 0xbf3bef4f, 0x3da15ed8, 0x3a97961a, 0xbd54c06c, 
    0xbe8965dd, 0x3f2d6fb4, 0x3e48eb45, 0xbde34794, 0xbe00f6db, 0x3f14c255, 0x3df555ca, 0x3d9d3ae9, 
    0xbe1487f5, 0xbec6ba45, 0x3f805732, 0xbed1fe29, 0x3ed23766, 0xbdc5d9dd, 0x3f28e6d7, 0xbf836bcf, 
    0x3e3d4f51, 0xbf12575b, 0xbe06f523, 0x3e652565, 0x3f38fb2a, 0x3e044d3a, 0xbfa1c872, 0xbe65fc7b, 
    0xbdb75f7d, 0xbf43cc2a, 0xbcc16d8d, 0x3edda5de, 0x3ed64fdc, 0x3eb26f26, 0xbecddb6e, 0x3df9d7c9, 
    0xbc95ceab, 0xbdb13b67, 0xbeed6563, 0xbefad39f, 0xbf43ce12, 0xbed3e302, 0xbed62776, 0xbf646f74, 
    0xbe55dbd6, 0x3edb12ba, 0xbac9f5a2, 0xbd883641, 0x3ea7ba53, 0x3f17f370, 0xbe69b3f0, 0xbf661e02, 
    0x3f241041, 0x3d8fc862, 0xbea30f76, 0xbf006493, 0xbdfebc22, 0xbc9aea16, 0xbd806287, 0x3c4cc3f1
};

static const uint32_t _K22[] = {
    0xbfd57df8, 0x4021a61a, 0x3f565917, 0xc0211c77, 0x40009537, 0xbffa92e1, 0x3f143031, 0x3fdbedff, 
    0x407e8ad0, 0xbf4ace62, 0xbd3d8240, 0xbfa17ab4, 0x3f3bc6c6, 0x3fc61a19, 0xc005e117, 0x3fe25cb1
};

static const uint32_t _K28[] = {
    0x3de4c179, 0xbf08af64, 0xbee61ad4, 0x3f6c0056, 0x3ee331cd, 0xbf9478fe, 0x3f869380, 0x3e687f05, 
    0xbf037ecd, 0x3f039ba6, 0x3f0ce923, 0x3e9d832e, 0xbec9e4f7, 0xbf6ce1d1, 0x3f3c5d15, 0x3f0d84a0, 
    0xbfd09176, 0x3d8570f3, 0x3f5df236, 0xbef3c7fe, 0x3ed08f49, 0x3e645507, 0xbf295d55, 0x3effc54e, 
    0xbf5ba3cb, 0xbf609b13, 0x3d410a51, 0xc022dea4, 0xbf06ddd7, 0x3f4a1aab, 0xbf183ae1, 0xbd71295a, 
    0xbf0748be, 0xbf8d33ec, 0xbfdc049e, 0xbf51236e, 0x3ef1fae0, 0x3f784cc2, 0x3c7a5fb2, 0xbf401bdc, 
    0xbfa30bc5, 0x3eb9760f, 0xbda30a01, 0x3e76e78f, 0x3f5d0b3f, 0xbed4520a, 0xbe92c541, 0xbfbe619c, 
    0xc00b7fbc, 0x3f714819, 0xbed44b33, 0xbdab86d1, 0xc03e3325, 0x3eb5e0d9, 0xbdb217c9, 0xbf2d456e, 
    0x3f4c2ca3, 0x3eb86b5d, 0x3dc13f15, 0x3e361393, 0xbed81b32, 0x3e86d2b8, 0xbf210d08, 0xbf6c98de, 
    0x3ee7c5b4, 0xbf4c8cdd, 0xbf40a729, 0xbed3141c, 0xbf74463d, 0x3e82892d, 0x3e4119bd, 0xbfc8258c, 
    0x3f2c0e85, 0xbfbadb51, 0xbfa11315, 0x3f265b6e, 0xbd856d92, 0x3f20a053, 0xbeed7b1d, 0x3f1c4d78
};

static const uint32_t _K30[] = {
    0x3e62dce9, 0xbe534c61, 0xbe9b536e, 0xbeb2d27b, 0xbd856bd2
};

// Memory mapped buffers
#define _K12             ((float *)_K12)                     // f32[16,3,16] (3072 bytes) 
#define _K15             ((float *)_K15)                     // f32[16] (64 bytes) 
#define _K19             ((float *)_K19)                     // f32[16,3,16] (3072 bytes) 
#define _K22             ((float *)_K22)                     // f32[16] (64 bytes) 
#define _K28             ((float *)_K28)                     // f32[5,16] (320 bytes) 
#define _K30             ((float *)_K30)                     // f32[5] (20 bytes) 
#define _K5              ((float *)_K5)                      // f32[16,3,6] (1152 bytes) 
#define _K8              ((float *)_K8)                      // f32[16] (64 bytes) 
#define _K3              ((int8_t *)(_state + 0x00000000))   // s8[2608] (2608 bytes) 
#define _K10             ((float *)(_buffer + 0x00000000))   // f32[50,16] (3200 bytes) 
#define _K11             ((float *)(_buffer + 0x00000c80))   // f32[50,16] (3200 bytes) 
#define _K13             ((float *)(_buffer + 0x00000000))   // f32[50,16] (3200 bytes) 
#define _K17             ((float *)(_buffer + 0x00000c80))   // f32[50,16] (3200 bytes) 
#define _K18             ((float *)(_buffer + 0x00000000))   // f32[50,16] (3200 bytes) 
#define _K2              ((float *)(_buffer + 0x00000000))   // f32[100,6] (2400 bytes) 
#define _K20             ((float *)(_buffer + 0x00000c80))   // f32[50,16] (3200 bytes) 
#define _K24             ((float *)(_buffer + 0x00000000))   // f32[50,16] (3200 bytes) 
#define _K26             ((float *)(_buffer + 0x00000c80))   // f32[25,16] (1600 bytes) 
#define _K27             ((float *)(_buffer + 0x00000000))   // f32[16] (64 bytes) 
#define _K29             ((float *)(_buffer + 0x00000040))   // f32[5] (20 bytes) 
#define _K31             ((float *)(_buffer + 0x00000000))   // f32[5] (20 bytes) 
#define _K4              ((float *)(_buffer + 0x00000960))   // f32[50,16] (3200 bytes) 
#define _K6              ((float *)(_buffer + 0x000015e0))   // f32[50,16] (3200 bytes) 

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t* buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	cbuffer_reset(dest);
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void* cbuffer_readptr(cbuffer_t* buf, int offset, int* can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int can_read_bytes;
	void* src_ptr = cbuffer_readptr(buf, offset, &can_read_bytes);

	int c0 = (count < can_read_bytes) ? count : can_read_bytes;
	memcpy(dst, src_ptr, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
	int window_count;				// Number of input chunks in output window.
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_NOMEM -2

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeuef32(void* restrict handle, void* restrict dst, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = fep->window_count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_NOMEM;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_NOMEM;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

static inline float mac_f32(const float* restrict a, const float* restrict b, int count)
{
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += *a++ * *b++;
	}
	return sum;
}

static inline void conv1d_flat_f32(
	const float* restrict input,
	const float* restrict weight,
	float* restrict output,
	int top,
	int bottom,
	int n_output_rows,
	int filters,
	int strides,
	int kernel_size)
{
	for (int i = 0; i < n_output_rows; i++) {
		const float* wp = weight;		// Weight matrix
		const float* bp = input;		// Input matrix
		const int step = i * strides;	// Row size
		int len = kernel_size;			// Normally do one kernel

		int skip = top - step;			// Pad top?
		if (skip > 0) {
			len -= skip;				// Trim kernel length
			wp += skip;					// Advance kernel
		}
		else {						// No top padding,
			bp -= skip;					// Rollback input
		}

		skip = step + len - bottom;		// Pad bottom?
		if (skip > 0)
			len -= skip;				// Just cut the kernel at end

		float* op = output + i * filters;
		for (int j = 0; j < filters; j++) {
			*op++ = mac_f32(wp + j * kernel_size, bp, len);
		}
	}
}

static inline void add_f32(
	const float* restrict a,
	const float* restrict b,
	int l, int g1, int m, int g2, int r,
	float* restrict output)
{
	int index = 0;
	for (int x = 0; x < l; x++) {
		for (int i = 0; i < g1; i++) {
			for (int y = 0; y < m; y++) {
				for (int j = 0; j < g2; j++) {
					for (int z = 0; z < r; z++) {
						output[index] = a[index] + b[x * m * r + y * r + z];
						index++;
					}
				}
			}
		}
	}
}

static inline void relu_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		const float value = *x++;
		*result++ = value > 0 ? value : 0;
	}
}

static inline float maxpool1d_f32_max(const float *restrict x, int ncols, int pool_size)
{
    float max = -FLT_MAX;
    for (int i = 0; i < pool_size; i++) {
        const float value = *(x + i * ncols);
        if (value > max)
            max = value;
    }
    return max;
}

static inline void maxpool1d_f32_row(const float* restrict x, int pool_size, int ncols, float* restrict result)
{
    for (int i = 0; i < ncols; i++) {
        const float* xp = x + i;
        *result++ = maxpool1d_f32_max(xp, ncols, pool_size);
    }
}

static inline void maxpool1d_valid_f32(
    const float* restrict input,
    int pool_size,
    int strides,
    int ncols,
    int n_output_rows,
    float* restrict result)
{
    int input_pointer_step = ncols * strides;

    for (int i = 0; i < n_output_rows; i++) {
        const float* input_current = input + (i * input_pointer_step);
        float* rp = result + (i * ncols);
        maxpool1d_f32_row(input_current, pool_size, ncols, rp);
    }
}

static inline float _globav1d_f32_mean(const float *restrict x, int nchannel, int nsteps)
{
	float mean = 0.0;
	for (int i = 0; i < nsteps; i++) {
		const float value = *(x + i * nchannel);
		mean = mean + value;
	}
	mean = mean/(float)nsteps;
	return mean;
}

static inline void globav1d_f32(const float *restrict x, int nsteps, int nchannel, float *restrict result)
{
	// Loop over all channels
	for (int i = 0; i < nchannel; i++) {
		const float* xp = x + i;
		*result++ = _globav1d_f32_mean(xp, nchannel, nsteps);
	}
}

static inline void dott_f32(const float *restrict a, const float *restrict b, float *restrict out, int d0, int d1, int d2)
{
	for (int i = 0; i < d2; i++) {
		float* op = out;
		for (int j = 0; j < d1; j++) {
			*op++ = mac_f32(a + j * d0, b, d0);
		}
		out += d1;
		b += d0;
	}
}

static inline void softmax_f32(const float* restrict x, int count, float* restrict result)
{
	float sum = 0;
	for (int i = 0; i < count; i++) {
		float value = expf(x[i]);
		sum += value;
		result[i] = value;
	}
	for (int i = 0; i < count; i++) {
		result[i] /= sum;
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NOMEM (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueuef32(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_NOMEM;

	return IPWIN_RET_SUCCESS;
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param window_count Number of items (of size input_size) in each window
*/
static inline void fixwin_initf32(void* restrict handle, int input_size, int window_count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;
	fep->window_count = window_count;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * window_count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) return __ret; } while(0)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) return __ret;  } 

int IMAI_dequeue(float *restrict data_out) {    
    __RETURN_ERROR(fixwin_dequeuef32(_K3, _K2, 10));
    conv1d_flat_f32(_K2, _K5, _K4, 0, 600, 50, 16, 12, 18);
    add_f32(_K4, _K8, 1, 1, 1, 50, 16, _K6);
    relu_f32(_K6, 800, _K10);
    conv1d_flat_f32(_K10, _K12, _K11, 16, 816, 50, 16, 16, 48);
    add_f32(_K11, _K15, 1, 1, 1, 50, 16, _K13);
    relu_f32(_K13, 800, _K17);
    conv1d_flat_f32(_K17, _K19, _K18, 16, 816, 50, 16, 16, 48);
    add_f32(_K18, _K22, 1, 1, 1, 50, 16, _K20);
    relu_f32(_K20, 800, _K24);
    maxpool1d_valid_f32(_K24, 2, 2, 16, 25, _K26);
    globav1d_f32(_K26, 25, 16, _K27);
    dott_f32(_K28, _K27, _K29, 16, 5, 1);
    add_f32(_K29, _K30, 1, 1, 1, 1, 5, _K31);
    softmax_f32(_K31, 5, data_out);
    return 0;
}

int IMAI_enqueue(const float *restrict data_in) {    
    __RETURN_ERROR(fixwin_enqueuef32(_K3, data_in));
    return 0;
}

void IMAI_init(void) {    
    fixwin_initf32(_K3, 24, 100);
}

