-- MySQL dump 10.13  Distrib 8.0.21, for Linux (x86_64)
--
-- Host: localhost    Database: office
-- ------------------------------------------------------
-- Server version	8.0.21-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `office`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `office` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `office`;

--
-- Table structure for table `Departments`
--

DROP TABLE IF EXISTS `Departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Departments` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Departments`
--

LOCK TABLES `Departments` WRITE;
/*!40000 ALTER TABLE `Departments` DISABLE KEYS */;
INSERT INTO `Departments` VALUES (1,'Development'),(2,'Design'),(3,'Human Resources');
/*!40000 ALTER TABLE `Departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Persons`
--

DROP TABLE IF EXISTS `Persons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Persons` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) DEFAULT NULL,
  `Age` int DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Persons`
--

LOCK TABLES `Persons` WRITE;
/*!40000 ALTER TABLE `Persons` DISABLE KEYS */;
INSERT INTO `Persons` VALUES (1,'Karen Hovhannisyan',26),(2,'Arman Khachatryan',24),(3,'Petros Poxosyan',36),(4,'Poxos Petrosyan',36),(5,'Sargis Sargsyan',20),(6,'Vazgen Aloyan',31);
/*!40000 ALTER TABLE `Persons` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Projects`
--

DROP TABLE IF EXISTS `Projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Projects` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) DEFAULT NULL,
  `Start` time NOT NULL,
  `End` time DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Projects`
--

LOCK TABLES `Projects` WRITE;
/*!40000 ALTER TABLE `Projects` DISABLE KEYS */;
INSERT INTO `Projects` VALUES (1,'facebook.com','12:00:00','18:00:00'),(2,'google.com','18:00:00',NULL);
/*!40000 ALTER TABLE `Projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Workers_Projects`
--

DROP TABLE IF EXISTS `Workers_Projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Workers_Projects` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `PersonID` int DEFAULT NULL,
  `DepartmentID` int DEFAULT NULL,
  `ProjectID` int DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `PersonID` (`PersonID`),
  KEY `DepartmentID` (`DepartmentID`),
  KEY `ProjectID` (`ProjectID`),
  CONSTRAINT `Workers_Projects_ibfk_1` FOREIGN KEY (`PersonID`) REFERENCES `Persons` (`ID`),
  CONSTRAINT `Workers_Projects_ibfk_2` FOREIGN KEY (`DepartmentID`) REFERENCES `Departments` (`ID`),
  CONSTRAINT `Workers_Projects_ibfk_3` FOREIGN KEY (`ProjectID`) REFERENCES `Projects` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Workers_Projects`
--

LOCK TABLES `Workers_Projects` WRITE;
/*!40000 ALTER TABLE `Workers_Projects` DISABLE KEYS */;
INSERT INTO `Workers_Projects` VALUES (1,2,1,1),(2,1,2,1),(3,6,3,1),(4,5,3,2),(5,3,1,2),(6,4,2,2);
/*!40000 ALTER TABLE `Workers_Projects` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-30 23:36:07
