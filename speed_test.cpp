//
// Created by Keegan Millard on 2018-12-05.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <unordered_map>

#include "PGM.h"
#include "Alpha.h"

using namespace std;

const string destdir = "./out_images/";
const string srcdir = "./input_images/";

std::unordered_map<string,Image*> image_map;

void create(string filename) {
    Image *im = Image::create(srcdir+filename);
    if(image_map.find(filename) == image_map.end())
        image_map.insert( make_pair <string, Image*>((string)filename,(Image*)im));
    else
        delete im;
}

void write(const string &filename) {
    Image *im = image_map[filename];
    im->write(destdir+filename);
}

void half_size(const string &filename){
    Image *im = image_map[filename];
    im->resize(0.5);
}

void double_size(const string &filename){
    Image *im = image_map[filename];
    im->resize(2.0);
}

struct TestObject {
    const string name;

    void run_test(const string &name, int iter) {
        using namespace std::chrono;
        auto start = high_resolution_clock::now();

        for(int x = 0; x < iter; x++)
            test();

        auto duration =  high_resolution_clock::now() - start;
        std::cout << name << " x" << to_string(iter) << '\n';
        std::cout << "ms: " << duration_cast<milliseconds>(duration).count() << '\n';
    }

    virtual void test() = 0;

};

struct CreateSmallAlpha : public TestObject {

    void test() override {
//        create("j.alpha");
//        create("j_clean.alpha");
//        create("j_star.alpha");
        create("p.alpha");
//        create("hi.alpha");
        create("feep.alpha");
        create("luna_small.alpha");
        create("image10_small.alpha");
        create("image15_small.alpha");

    }
};

struct CreateSmallPGM : public TestObject {

    void test() override {
        create("hi.pgm");
        create("feep.pgm");
        create("my.pgm");
        create("image10_small.pgm");
        create("image11_small.pgm");
        create("image15_small.pgm");
    }
};

struct CreateLargePGM : public TestObject {

    void test() override {
        create("einstein.pgm");
        create("image10.pgm");
        create("image16.pgm");
        create("image17.pgm");
        create("image21.pgm");
        create("image23.pgm");
        create("image24.pgm");
        create("image26.pgm");
    }

};

struct CreateLargeAlpha : public TestObject {

    void test() override {
        create("einstein.alpha");
        create("image10.alpha");
        create("image16.alpha");
        create("image17.alpha");
        create("image21.alpha");
        create("image23.alpha");
        create("image24.alpha");
        create("image26.alpha");
    }

};

struct WriteSmallAlpha : public TestObject {

    void test() override {
//        create("j.alpha");
//        create("j_clean.alpha");
//        create("j_star.alpha");
//        create_and_write("p.alpha");
//        create("hi.alpha");
        write("feep.alpha");
//        write("luna_small.alpha");
        write("image10_small.alpha");
        write("image15_small.alpha");

    }
};

struct WriteSmallPGM : public TestObject {

    void test() override {
//        create("j.pgm");
//        create("j_clean.pgm");
//        create("j_star.pgm");
//        create_and_write("p.pgm");
//        create("hi.pgm");
        write("feep.pgm");
//        write("luna_small.pgm");
        write("image10_small.pgm");
        write("image15_small.pgm");

    }
};

struct WriteLargeAlpha : public TestObject {

    void test() override {
        write("einstein.alpha");
        write("image10.alpha");
        write("image16.alpha");
        write("image17.alpha");
        write("image21.alpha");
        write("image23.alpha");
        write("image24.alpha");
        write("image26.alpha");
    }

};

struct WriteLargePGM : public TestObject {

    void test() override {
        write("einstein.pgm");
        write("image10.pgm");
        write("image16.pgm");
        write("image17.pgm");
        write("image21.pgm");
        write("image23.pgm");
        write("image24.pgm");
        write("image26.pgm");
    }

};

struct ResizePGM : public TestObject {

    void test() override {
        half_size("einstein.pgm");
        half_size("image10.pgm");
        half_size("image16.pgm");
        half_size("image17.pgm");
        half_size("image21.pgm");
        half_size("image23.pgm");
        half_size("image24.pgm");
        half_size("image26.pgm");

        double_size("einstein.pgm");
        double_size("image10.pgm");
        double_size("image16.pgm");
        double_size("image17.pgm");
        double_size("image21.pgm");
        double_size("image23.pgm");
        double_size("image24.pgm");
        double_size("image26.pgm");
    }

};

struct ResizeAlpha : public TestObject {

    void test() override {
        half_size("einstein.alpha");
        half_size("image10.alpha");
        half_size("image16.alpha");
        half_size("image17.alpha");
        half_size("image21.alpha");
        half_size("image23.alpha");
        half_size("image24.alpha");
        half_size("image26.alpha");

        double_size("einstein.alpha");
        double_size("image10.alpha");
        double_size("image16.alpha");
        double_size("image17.alpha");
        double_size("image21.alpha");
        double_size("image23.alpha");
        double_size("image24.alpha");
        double_size("image26.alpha");
    }

};

int main(int argc, char *argv[]) {

    try {
        //CreateSmallAlpha().run_test("CreateSmallAlpha", 100);
        CreateSmallPGM().run_test("CreateSmallPGM", 100);
        CreateLargeAlpha().run_test("CreateLargeAlpha", 1);
        CreateLargePGM().run_test("CreateLargePGM", 1);

        //WriteSmallAlpha().run_test("WriteSmallAlpha", 100);
        //WriteSmallPGM().run_test("WriteSmallPGM", 100);
		WriteLargeAlpha().run_test("WriteLargeAlpha", 1);
        WriteLargePGM().run_test("WriteLargePGM", 1);

        ResizeAlpha().run_test("ResizeAlpha", 1);
        ResizePGM().run_test("ResizeAlpha", 1);

    } catch(std::string &s){
        std::cout << s << '\n';
    }
    return 0;
}
