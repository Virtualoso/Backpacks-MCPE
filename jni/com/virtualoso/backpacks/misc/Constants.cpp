#include "Constants.h"

std::string Constants::MOD_ID = "Backpack";
std::string Constants::MOD_NAME = "Backpack";
std::string Constants::MOD_VERSION = "0.0.b1";
std::string Constants::FINGERPRINT = "@FINGERPRINT@";

std::string Constants::DOMAIN = "backpack";

std::string Constants::RECIPE_ENHANCE = Constants::DOMAIN + ":enhanceBackpack";
std::string Constants::RECIPE_INTELLIGENT = Constants::DOMAIN + ":intelligentWorkbench";
std::string Constants::RECIPE_RECOLOR = Constants::DOMAIN + ":recolorBackpack";

std::string Constants::UPDATE_FILE = "";

char Constants::Guis::OPEN_PERSONAL_BACKPACK = 0;
char Constants::Guis::OPEN_PERSONAL_SLOT = 1;

char Constants::GuiCommands::CLEAR = 1;
char Constants::GuiCommands::SAVE = 2;
char Constants::GuiCommands::PREV = 3;
char Constants::GuiCommands::NEXT = 4;

std::string Constants::NBT::INVENTORIES = "backpackInventories";
std::string Constants::NBT::INVENTORY_BACKPACK = "backpack";
std::string Constants::NBT::INVENTORY_PERSONAL_BACKPACK = "personalBackpack";
std::string Constants::NBT::INVENTORY_PICKUP_ITEMS = "pickupItems";
std::string Constants::NBT::INVENTORY_CRAFTING_GRID = "craftingGrid";
std::string Constants::NBT::INVENTORY_RECIPES = "recipes";
std::string Constants::NBT::INVENTORY_RECIPE = "recipe-";
std::string Constants::NBT::UID = "backpack-UID";
std::string Constants::NBT::NAME = "name";
std::string Constants::NBT::CUSTOM_NAME = "customName";
std::string Constants::NBT::SIZE = "size";
std::string Constants::NBT::SLOT = "slot";
std::string Constants::NBT::SLOTS_PER_ROW = "slotsPerRow";
std::string Constants::NBT::INTELLIGENT = "intelligent";
std::string Constants::NBT::TYPE = "type";
std::string Constants::NBT::PERSONAL_BACKPACK_OPEN = "personalBackpackOpen";