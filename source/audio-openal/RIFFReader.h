/*
 * Copyright (C) 2014  absurdworlds
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _awrts_RIFF_
#define _awrts_RIFF_
#include <string>

#include <awengine/common/types.h>
#include <awengine/io/ReadFile.h>

#include "SoundSample.h"

namespace awrts {
namespace audio {

// assuming Little Endian
enum class WaveFields {
	RiffHeader = 'FFIR',
	WaveTag = 'EVAW',
	Format = ' tmf',
	DataTag = 'atad'
};

enum class WaveFormat {
	PCM = 0x01,
	IEEE = 0x03,
	ALaw = 0x06,
	MuLaw = 0x07,
	IMAADPCM = 0x11,
	YamahaITUG723ADPCM = 0x16,
	GSM610 = 0x31,
	ITUG721ADPCM = 0x40,
	MPEG = 0x50,
	Extensible = 0xFFFE
};

bool readWAV(std::string path, SoundSample& sample) 
{
	io::ReadFile file(path);

	if(!file.isOpen()) {
		return false;
	}

	u32 riffHeader;
	file.read(&riffHeader,4);
	u32 fileSize;
	file.read(&fileSize,4);
	u32 waveTag;
	file.read(&waveTag,4);
	u32 format;
	file.read(&format,4);

	if((WaveFields)riffHeader != WaveFields::RiffHeader) {
		return false;
	} else if((WaveFields)waveTag != WaveFields::WaveTag) {
		return false;
	} else if((WaveFields)format != WaveFields::Format) {
		return false;
	}

	u32 headerLength;
	file.read(&headerLength,4);
	u16 type;
	file.read(&type,2);
	u16 channels;
	file.read(&channels,2);
	u32 sampleRate;
	file.read(&sampleRate,4);
	u32 bitRate;
	file.read(&bitRate,4);
	u16 bytesPerSample;
	file.read(&bytesPerSample,2);
	u16 bitsPerSample;
	file.read(&bitsPerSample,2);

	u32 dataTag;
	file.read(&dataTag,4);

	if((WaveFields)dataTag != WaveFields::DataTag) {
		return false;
	}

	u32 dataSize;
	file.read(&dataSize,4);

	sample.bitsPerSample = bitsPerSample;
	sample.channels = channels;
	sample.sampleRate = sampleRate;
	sample.size = dataSize;

	i8* data = new i8[dataSize*2];
	i32 bytesRead = file.read(data,dataSize);
	if(bytesRead < dataSize) {
		return false;
	}

	sample.data = data;

	return true;
}

}
} //namespace awrts
#endif//_awrts_RIFF_
