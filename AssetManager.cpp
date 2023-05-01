#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{

	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{

	auto& texMap = sInstance->m_Textures;

	auto pairFound = texMap.find(filename);

	if(pairFound!=texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}

}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{

	auto& sBuferMap = sInstance->m_SoundBuffer;

	auto pairFound = sBuferMap.find(filename);

	if (pairFound != sBuferMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& sBufer = sBuferMap[filename];
		sBufer.loadFromFile(filename);
		return sBufer;
	}

}

sf::Font& AssetManager::GetFont(std::string const& filename)
{

	auto& fontMap = sInstance->m_Font;

	auto pairFound = fontMap.find(filename);

	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}

}