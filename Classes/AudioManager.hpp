/*
Copyright (c) 2018 Inverse Palindrome
Apophis - AudioManager.hpp
InversePalindrome.com
*/


#pragma once

#include <cocos/audio/include/AudioEngine.h>

#include <string>
#include <unordered_set>


class AudioManager
{
public:
	AudioManager() = default;
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator= (const AudioManager&) = delete;

	static AudioManager& getInstance();

	int playSound(const std::string& filename, bool loop = false);
	int playMusic(const std::string& filename, bool loop = false);

	static void resumeAudio(int audioID);
	void resumeSounds();
	void resumeMusic();

	static void pauseAudio(int audioID);
	void pauseSounds();
	void pauseMusic();

private:
	std::unordered_set<int> soundIDs;
	std::unordered_set<int> musicIDs;
};