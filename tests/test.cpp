#include <gtest/gtest.h>
#include <filesystem>
#include <vector>
#include "FileSystemService.h"
#include "PathUtils.h"
#include "BasicCommands.h"
#include "FileCommands.h"
#include "FindCommands.h"
#include "CommandParser.h"

namespace fs = std::filesystem;
namespace tfm {
    class FileSystemTest : public ::testing::Test {
    protected:
        const std::string testDir = "test_dir";
        const std::string testFile = "test_dir/test.txt";

        void SetUp() override {
            FileSystemService::createDirectory(testDir);
        }

        void TearDown() override {
            fs::remove_all(testDir);

        }
    };

    TEST_F(FileSystemTest, CreateDirectory) {
        auto result = FileSystemService::createDirectory("test_dir/nested");
        EXPECT_FALSE(result.has_value());
    }

    TEST_F(FileSystemTest, CreateFile) {
        auto result = FileSystemService::createFile(testFile);
        EXPECT_FALSE(result.has_value());
        EXPECT_TRUE(fs::exists(testFile));
    }
    TEST_F(FileSystemTest, WriteAndReadFile) {
        const std::string content = "Hello, World!";
        auto writeError = FileSystemService::writeFile(testFile, content);
        EXPECT_FALSE(writeError.has_value());

        auto readContent = FileSystemService::readFile(testFile);
        EXPECT_TRUE(readContent.has_value());
        EXPECT_EQ(readContent.value(), content);
    }
    TEST_F(FileSystemTest, ListDirectory) {
        FileSystemService::createFile(testFile);

        auto result = FileSystemService::listDirectory(testDir);
        EXPECT_TRUE(result.has_value());
        EXPECT_GT(result->size(), 0u);
    }
    TEST_F(FileSystemTest, ChangeDirectory) {
        auto error = FileSystemService::changeDirectory(testDir);
        EXPECT_FALSE(error.has_value());
        EXPECT_EQ(fs::current_path().filename().string(), testDir);
    }
    TEST_F(FileSystemTest, PathUtils) {
        fs::path relative = "test.txt";
        fs::path absolute = PathUtils::makeAbsolute(relative);
        EXPECT_TRUE(absolute.is_absolute());

        EXPECT_EQ(PathUtils::getFilename(absolute), "test.txt");
        EXPECT_TRUE(PathUtils::isEmpty(fs::path()));
    }
    TEST(FileSystemServiceStandalone, CurrentPath) {
        auto path = FileSystemService::getCurrentPath();
        EXPECT_FALSE(path.empty());
    }
    TEST(FileSystemServiceStandalone, ExistsAndIsDirectory) {
        auto path = fs::current_path();
        EXPECT_TRUE(FileSystemService::exists(path));
        EXPECT_TRUE(FileSystemService::isDirectory(path));
    }
    TEST(CommandsTest, HelpCommand) {
        HelpCommand help;
        std::vector<std::string> emptyArgs;
        EXPECT_TRUE(help.execute(emptyArgs));
    }

    TEST(CommandsTest, PwdCommand) {
        PwdCommand pwd;
        std::vector<std::string> emptyArgs;
        EXPECT_TRUE(pwd.execute(emptyArgs));
    }
    TEST(CommandsTest, MkdirCommandWrongArgs) {
        MkdirCommand mkdir;
        std::vector<std::string> noArgs;
        EXPECT_FALSE(mkdir.execute(noArgs));

        std::vector<std::string> twoArgs = {"dir1", "dir2"};
        EXPECT_FALSE(mkdir.execute(twoArgs));
    }
    TEST(CommandsTest, TouchCommandWrongArgs) {
        TouchCommand touch;
        std::vector<std::string> noArgs;
        EXPECT_FALSE(touch.execute(noArgs));
    }
    TEST(CommandsTest, CatCommandWrongArgs) {
        CatCommand cat;
        std::vector<std::string> noArgs;
        EXPECT_FALSE(cat.execute(noArgs));
    }
    TEST(CommandsTest, WriteCommandWrongArgs) {
        WriteCommand write;
        std::vector<std::string> noArgs;
        EXPECT_FALSE(write.execute(noArgs));

        std::vector<std::string> onlyFile = {"file.txt"};
        EXPECT_FALSE(write.execute(onlyFile));
    }
    TEST(CommandsTest, FindCommandsWrongArgs) {
        FindNameCommand findName;
        std::vector<std::string> noArgs;
        EXPECT_FALSE(findName.execute(noArgs));

        FindPathCommand findPath;
        EXPECT_FALSE(findPath.execute(noArgs));
    }
}