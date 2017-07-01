#pragma once

#include <string>
#include <chrono>
#include <ratio>
#include <memory>
#include <vector>

class GameCallbacks;
class SkinInfoFactory;
class Vibration;
class SoundPlayer;
namespace minecraft {
	namespace api {
		class Api;
	};
};
class Whitelist;
class OpsList;
class MinecraftEventing;
enum GameType;
class Level;
class GameMode;
class Player;
namespace mce {
	class UUID;
};
class NetEventCallback;
class LevelSettings;
class ResourcePackManager;
class NetworkIdentifier;

class Minecraft {
public:

	char filler1[112];
	/* size = 0x70 */

	// non virtual
	Minecraft(IMinecraftApp&, GameCallbacks&, SkinInfoFactory&, SoundPlayer&, minecraft::api::Api&, Whitelist const&, OpsList const&, FilePathManager*, std::chrono::duration<long long, std::ratio<1ll, 1ll>>, MinecraftEventing&);
	~Minecraft();
	bool isModded();
	void* getCommands();
	void* getNetworkHandler();
	void* getLevel() const;
	void* getServerNetworkHandler();
	void* getEventing() const;
	void* getSimPaused() const;
	void* createGameMode(GameType, Level&);
	void* getLevelSource();
	void* hostMultiplayer(std::string const&, std::unique_ptr<Level, std::default_delete<Level>>, std::unique_ptr<GameMode, std::default_delete<GameMode>>, Player*, mce::UUID const&, std::unique_ptr<NetEventCallback, std::default_delete<NetEventCallback>>, int, bool, bool, bool, std::vector<std::string, std::allocator<std::string>> const&, std::string, int, int, int, int);
	void* getResourceLoader();
	void* getStructureManager();
	void initAsDedicatedServer();
	void init(bool);
	void update();
	void* createLevel(std::string const&, std::string const&, std::string const&, std::string const&, LevelSettings const&, ResourcePackManager&);
	void* getGameMode();
	void tickSimtime(int, int);
	void setLeaveGame();
	void tickRealtime(int, int);
	void* validateLevel(std::string const&, std::string const&, LevelSettings const&);
	bool isOnlineClient();
	void* getPacketSender();
	void setGameModeReal(GameType);
	void setSimTimePause(bool);
	void setSimTimeScale(float);
	void* startClientGame(std::unique_ptr<NetEventCallback, std::default_delete<NetEventCallback>>);
	void disconnectClient(NetworkIdentifier const&, std::string const&);
	void* getServerLocator();
	void resetGameSession();
	void activateWhitelist();
	void* getNetEventCallback();
	void setupServerCommands(std::string const&, std::string const&);
	void* getNetworkStatistics();
	void* onClientCreatedLevel(std::unique_ptr<Level, std::default_delete<Level>>);
	void* getTimer();
	void stopGame();
	void teardown();
	bool isInitialized() const;
	void* postServerUpdate();
    bool usesNonLocalConnection(NetworkIdentifier const&);
	void* getServerLocator() const;
    void* getNetworkHandler() const;
};
