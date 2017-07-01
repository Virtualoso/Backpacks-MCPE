#pragma once

#include <string>
#include <memory>

class Minecraft;
class LevelSettings;
class AbstractScreen;
enum class GameType;
enum class HoloGameMode;
class HolographicPlatform;
class LocalPlayer;
enum class FocusImpact;
namespace Realms {
	class World;
};
namespace Social {
	class GameConnectionInfo;
	class XboxLiveGameInfo;
};
class Player;
class VoiceSystem;
class Timer;
enum class DirectionId;
class Entity;
class TextureData;
class BuildActionIntention;
class VoiceCommand;
class Level;
class Dimension;
enum class InputMode;
namespace ui {
	class GameEventNotification;
};
class ResourcePacksInfoData;
enum class HoloUIInputMode;
enum class ResourcePackResponse;

class MinecraftClient {
public:

	char filler1[720 - 4];
	/* size = 0x2D0 */

	// virtual

	// non virtual

	// static
	static std::string WORLD_PATH;
	static std::string SETTINGS_PATH;
	static void* GUI_SCALE_VALUES;
	static void* _hasInitedStatics;
	static int INTERACTION_FREQ_MS;
	static std::string RESOURCE_PACKS_SAVE_FILENAME;
};
