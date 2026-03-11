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
}