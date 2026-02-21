import time
import math
import deepcraft_model as m
import gc
import array
import random
import sys
import select
from machine import PDM_PCM, Pin
import machine

#Instantiate model
model = m.DEEPCRAFT()

SAMPLE_RATE_HZ = 16000  # Desired sample rate in Hz
AUDIO_BUFFER_SIZE = 512  # Size of the audio buffer
AUDIO_BITS_PER_SAMPLE = 16  # Dynamic range in bits
MICROPHONE_GAIN = 12  # Microphone gain setting(best prediction observed at 12)
DIGITAL_BOOST_FACTOR = 50.0  # Digital boost factor for input signal
IMAI_DATA_OUT_SYMBOLS = ["unlabelled", "air", "plastic", "plastic_out", "wood", "wood_out"]


# Initialize label scores and labels
label_scores = [0.0] * len(IMAI_DATA_OUT_SYMBOLS)
label_text = IMAI_DATA_OUT_SYMBOLS
data_out = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))


# PDM_PCM configuration
clk_pin = "P10_4"
data_pin = "P10_5"
rx_buf = array.array('h', [0] * AUDIO_BUFFER_SIZE)

# Function to normalize sample into range [-1, 1]
def sample_normalize(sample):
    return sample / float(1 << (AUDIO_BITS_PER_SAMPLE - 1))

def main():
    
    machine.freq(machine.AUDIO_PDM_24_576_000_HZ)

    # Initialize the model
    result = model.init()
    
    # Initialize audio
    pdm_pcm = PDM_PCM(
        0,
        sck=clk_pin,
        data=data_pin,
        sample_rate=SAMPLE_RATE_HZ,
        decimation_rate=64,
        bits=PDM_PCM.BITS_16,
        format=PDM_PCM.MONO_LEFT,
        left_gain=MICROPHONE_GAIN,
        right_gain=MICROPHONE_GAIN,
    )
    pdm_pcm.init()
    print("PDM initialized successfully")

    while True:
        
        num = pdm_pcm.readinto(rx_buf)

        sample_max = 0.0
        audio_count = num // 2

        for i in range(audio_count):
            # Get sample from rx_buf
            raw_sample = rx_buf[i]* DIGITAL_BOOST_FACTOR

            # Normalize the sample to range [-1, 1]
            normalized_sample = sample_normalize(raw_sample)

            # Apply digital boost factor
            boosted_sample = normalized_sample 

            # Pass the boosted sample to the model
            result = model.enqueue([boosted_sample])

            sample_abs = abs(boosted_sample)
            if sample_abs > sample_max:
                sample_max = sample_abs

            # Check if there is any model output to process
            output_status = model.dequeue(data_out)
            if output_status == 0: 
                max_score = -math.inf
                best_label = 0
                for idx, score in enumerate(data_out):
                    print(f"Label: {label_text[idx]:<10} Score(%): {score*100:.4f}")
                    if score > max_score:
                        max_score = score
                        best_label = idx

                print("\r\n")
                print(f"Output: {label_text[best_label]:<30}\r\n")


if __name__ == "__main__":
    main()