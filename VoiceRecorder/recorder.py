import sounddevice as sd
from scipy.io.wavfile import write


freq = 44000

duration = 10

recording = sd.rec(int(duration * freq), samplerate = freq, channels = 1)

sd.wait()

write("recording1.wav", freq, recording)