from machine import PDM_PCM, Pin, freq, AUDIO_PDM_24_576_000_HZ
import time
import struct
import uio

clk_pin = "P10_4"
data_pin = "P10_5"

rx_buf = bytearray([0] * 128)
            
def record_audio(filename, time_sec):
    with uio.open(filename, "wb") as f:
        f.write(wav_header)
        start_time = time.time()
        #Start conversion
        pdm_pcm.init()
        while time.time() - start_time < time_sec:  # record for "time_sec" second
            num_read = pdm_pcm.readinto(rx_buf)
            f.write(rx_buf)

#Set clock according to sample rate
freq(AUDIO_PDM_24_576_000_HZ)

pdm_pcm = PDM_PCM(
    0,
    sck=clk_pin,
    data=data_pin,
    sample_rate=8000,
    decimation_rate=64,
    bits=PDM_PCM.BITS_16,
    format=PDM_PCM.MONO_LEFT,
    left_gain=20,
    right_gain=20,
)


# Create a WAV file header
wav_header = bytearray(44)  # 44-byte WAV header
struct.pack_into('<4sI4s4sIHHIIHH4sI', wav_header, 0,
                 b'RIFF',          # ChunkID
                 480036,           # ChunkSize (36 + 480,000)
                 b'WAVE',          # Format
                 b'fmt ',          # Subchunk1ID
                 16,               # Subchunk1Size
                 1,                # AudioFormat (PCM)
                 1,                # NumChannels (MONO_LEFT)
                 8000,             # SampleRate
                 16000,           # ByteRate (8000 * 1 * 2)
                 2,               # BlockAlign (1 * 2)
                 16,               # BitsPerSample
                 b'data',          # Subchunk2ID
                 480000)          # Subchunk2Size

# Record audio for mentioned time period(in secs) and store raw values to given .wav file
record_audio("pcm_audio.wav", 30)

pdm_pcm.deinit()