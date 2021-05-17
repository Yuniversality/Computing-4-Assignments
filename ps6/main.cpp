// Copyright 2021 Ethan Yu

#include <iostream>
#include <fstream>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/regex.hpp>

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int agrc, char* argv[]) {
    std::string fileName = argv[1];
    const std::string inputFileName(fileName);
    std::ifstream inputFile{ fileName };
    fileName = fileName + ".rpt";
    const std::string outputFileName(fileName);
    std::ofstream outputFile{ fileName };

    boost::regex startExpr{"^([\\d]{4})\\-([\\d]{2})\\-([\\d]{2})\\s([\\d]{2}):([\\d]{2}):([\\d]{2}):\\s(\\(log\\.c\\.166\\) server started)\\s$"};  // NOLINT
    boost::regex endExpr{"^([\\d]{4})\\-([\\d]{2})\\-([\\d]{2})\\s([\\d]{2}):([\\d]{2}):([\\d]{2})\\.([\\d]{3}):INFO:oejs.AbstractConnector:Started SelectChannelConnector@0\\.0\\.0\\.0:9080$"};  // NOLINT
    boost::smatch matches;

    int startUpInProgress = 0;
    std::string line;
    int lineNum = 0;
    int startYear, startMonth, startDay, startHour, startMinute, startSecond;
    int endYear, endMonth, endDay, endHour, endMinute, endSecond;
    ptime startTime, endTime;

    auto findElapsedTime = [](ptime startTime, ptime endTime) {
        time_duration elapsedTime = endTime - startTime;
        std::cout << "Elapsed Time: " << elapsedTime.hours() <<
          ":" << elapsedTime.minutes() << ":" <<
          elapsedTime.seconds() << "\n\n";
    };

    if (inputFile && outputFile) {
        while (getline(inputFile, line)) {
            lineNum = lineNum + 1;
            outputFile << line << std::endl;

            if (boost::regex_match(line, matches, startExpr)) {
                if (startUpInProgress) {
                    std::cout << "Status: Failure \n\n";
                }

                startUpInProgress = 1;
                startYear = std::stoi(matches.str(1));
                startMonth = std::stoi(matches.str(2));
                startDay = std::stoi(matches.str(3));
                startHour = std::stoi(matches.str(4));
                startMinute = std::stoi(matches.str(5));
                startSecond = std::stoi(matches.str(6));
                date startDate(startYear, startMonth, startDay);
                ptime start(startDate, time_duration(startHour,
                  startMinute, startSecond, 0));
                startTime = start;

                std::cout << "Starting Up on Line " << lineNum << std::endl;
                std::cout << "Timestamp: " << startYear << "-" << startMonth
                  << "-" << startDay << " " << startHour << ":" <<
                  startMinute << ":" << startSecond << std::endl;
            } else if (boost::regex_match(line, matches, endExpr)) {
                if (startUpInProgress) {
                    std::cout << "Status: Success \n";

                    endYear = std::stoi(matches.str(1));
                    endMonth = std::stoi(matches.str(2));
                    endDay = std::stoi(matches.str(3));
                    endHour = std::stoi(matches.str(4));
                    endMinute = std::stoi(matches.str(5));
                    endSecond = std::stoi(matches.str(6));
                    date endDate(endYear, endMonth, endDay);
                    ptime end(endDate,
                      time_duration(endHour, endMinute, endSecond, 0));
                    endTime = end;

                    findElapsedTime(startTime, endTime);
                }
                startUpInProgress = 0;
            }
        }
        if (startUpInProgress) {
            std::cout << "Status: Failure \n\n";
        }
    } else {
        std::cout << "There was a problem with the files \n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

