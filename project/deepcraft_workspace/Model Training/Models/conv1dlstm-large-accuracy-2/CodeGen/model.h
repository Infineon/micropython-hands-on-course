/*
* ImagiNet Compiler 5.8.4292+50129d917517243fc033cba30ce355705c84a08c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/16/2026 23:39:04 UTC. Any changes will be lost.
* 
* Model ID  e1d859c4-289e-4f1b-aa75-d3be397d5fa3
* 
* Memory    Size                      Efficiency
* Buffers   15200 bytes (RAM)         84 %
* State     2864 bytes (RAM)          100 %
* Readonly  84948 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-large-accuracy-2
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | On
* 2           | Off
* 3           | Dimmer
* 4           | Lighter
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param dataout Output Features. Output float[5].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *dataout);
* 
*  @description: Try write data to model.
*  @param datain Input features. Input float[2,3].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *datain);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Initializes buffers to initial state.
*  void IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#include <stdbool.h>
#include <stdint.h>
#define IMAI_API_QUEUE

typedef int8_t q7_t;         // 8-bit fractional data type in Q1.7 format.
typedef int16_t q15_t;       // 16-bit fractional data type in Q1.15 format.
typedef int32_t q31_t;       // 32-bit fractional data type in Q1.31 format.
typedef int64_t q63_t;       // 64-bit fractional data type in Q1.63 format.

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xc4, 0x59, 0xd8, 0xe1, 0x9e, 0x28, 0x1b, 0x4f, 0xaa, 0x75, 0xd3, 0xbe, 0x39, 0x7d, 0x5f, 0xa3}


// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_Q7	(0x31)
#define IMAGINET_TYPES_Q15	(0x32)
#define IMAGINET_TYPES_Q31	(0x34)
#define IMAGINET_TYPES_BOOL	(0x41)
#define IMAGINET_TYPES_STRING	(0x54)
#define IMAGINET_TYPES_D8	(0x61)
#define IMAGINET_TYPES_D16	(0x62)
#define IMAGINET_TYPES_D32	(0x64)
#define IMAGINET_TYPES_UINT8	(0x71)
#define IMAGINET_TYPES_UINT16	(0x72)
#define IMAGINET_TYPES_UINT32	(0x74)
#define IMAGINET_TYPES_UINT64	(0x78)

// dataout [5] (20 bytes)
#define IMAI_DATAOUT_RANK (1)
#define IMAI_DATAOUT_SHAPE (((int[]){5})
#define IMAI_DATAOUT_COUNT (5)
#define IMAI_DATAOUT_TYPE float
#define IMAI_DATAOUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATAOUT_SHIFT 0
#define IMAI_DATAOUT_OFFSET 0
#define IMAI_DATAOUT_SCALE 1
#define IMAI_DATAOUT_SYMBOLS {"unlabeled}", "On", "Off", "Dimmer", "Lighter"}

// datain [2,3] (24 bytes)
#define IMAI_DATAIN_RANK (2)
#define IMAI_DATAIN_SHAPE (((int[]){3, 2})
#define IMAI_DATAIN_COUNT (6)
#define IMAI_DATAIN_TYPE float
#define IMAI_DATAIN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATAIN_SHIFT 0
#define IMAI_DATAIN_OFFSET 0
#define IMAI_DATAIN_SCALE 1
#define IMAI_DATAIN_SYMBOLS {"X", "Y", "Z"}

#define IMAI_KEY_MAX (89)

// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_ERROR -2
#define IMAI_RET_STREAMEND -3

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

// Exported methods
int IMAI_dequeue(float *restrict dataout);
int IMAI_enqueue(const float *restrict datain);
void IMAI_finalize(void);
void IMAI_init(void);

// Profiling regions
#define IMAI_REGIONS_COUNT 0
#define IMAI_REGIONS_NAMES {}
typedef enum {IMAI_REGIONS_EMPTY} IMAI_Region_t;

typedef enum {
    IMAI_PARAM_UNDEFINED = 0,
    IMAI_PARAM_INPUT = 1,
    IMAI_PARAM_OUTPUT = 2,
    IMAI_PARAM_REFERENCE = 3,
    IMAI_PARAM_HANDLE = 7,
} IMAI_param_attrib;

typedef char *label_text_t;

typedef struct {
    char* name;
    int size;
    label_text_t *labels;
} IMAI_shape_dim;

typedef struct {
    char* name;
    IMAI_param_attrib attrib;
    int32_t rank;
    IMAI_shape_dim *shape;
    int32_t count;
    int32_t type_id;
    float frequency;
    int shift;
    float scale;
    long offset;
} IMAI_param_def;

typedef enum {
    IMAI_FUNC_ATTRIB_NONE = 0,
    IMAI_FUNC_ATTRIB_CAN_FAIL = 1,
    IMAI_FUNC_ATTRIB_PUBLIC = 2,
    IMAI_FUNC_ATTRIB_INIT = 4,
    IMAI_FUNC_ATTRIB_DESTRUCTOR = 8,
} IMAI_func_attrib;

typedef struct {
    char* name;
    char* description;
    void* fn_ptr;
    IMAI_func_attrib attrib;
    int32_t param_count;
    IMAI_param_def *param_list;
} IMAI_func_def;

typedef struct {
    uint32_t size;
    uint32_t peak_usage;
} IMAI_mem_usage;

typedef enum {
    IMAI_API_TYPE_UNDEFINED = 0,
    IMAI_API_TYPE_FUNCTION = 1,
    IMAI_API_TYPE_QUEUE = 2,
    IMAI_API_TYPE_QUEUE_TIME = 3,
    IMAI_API_TYPE_USER_DEFINED = 4,
} IMAI_api_type;

typedef struct {
    uint32_t api_ver;
    uint8_t id[16];
    IMAI_api_type api_type;
    char* prefix;
    IMAI_mem_usage buffer_mem;
    IMAI_mem_usage static_mem;
    IMAI_mem_usage readonly_mem;
    int32_t func_count;
    IMAI_func_def *func_list;
} IMAI_api_def;

IMAI_api_def *IMAI_api(void);

