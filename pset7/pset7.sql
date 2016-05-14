-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(256) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `price` int(10) unsigned NOT NULL,
  `created_at` datetime NOT NULL,
  `bought` tinyint(1) NOT NULL,
  `sold` tinyint(1) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `balance` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (11,'BABA',1,79,'2016-04-03 17:27:42',1,0,1,NULL),(11,'BABA',1,79,'2016-04-03 17:27:59',0,1,2,NULL),(11,'BABA',3,79,'2016-04-03 17:38:44',1,0,3,NULL),(11,'Deposit',1,3499,'2016-04-03 20:10:19',0,0,5,NULL),(11,'FREE',3,0,'2016-04-03 20:13:03',1,0,6,NULL),(11,'BABA',5,79,'2016-04-03 20:13:17',1,0,7,NULL),(11,'FREE',2,0,'2016-04-03 20:15:34',1,0,8,NULL),(11,'FREE',2,0,'2016-04-03 20:18:43',1,0,9,NULL),(11,'FREE',28,0,'2016-04-03 20:18:57',0,1,10,NULL),(11,'FREE',12000,0,'2016-04-03 20:20:28',1,0,11,NULL),(11,'Deposit',1,89,'2016-04-03 20:27:18',0,0,12,NULL),(11,'Deposit',0,78,'2016-04-03 20:28:14',0,0,13,NULL),(11,'FB',34,116,'2016-04-03 20:29:51',1,0,14,NULL),(11,'SPY',2,207,'2016-04-03 20:31:17',1,0,15,NULL),(11,'FREE',1,0,'2016-04-03 20:32:00',1,0,16,NULL),(11,'FREE',3,0,'2016-04-03 20:34:34',1,0,17,NULL),(11,'SP',1,24,'2016-04-03 20:38:36',1,0,18,NULL),(11,'Deposit',0,45,'2016-04-03 22:08:53',0,0,19,11154),(11,'AMZN',8,599,'2016-04-03 22:09:06',0,1,20,11158),(11,'FB',1,116,'2016-04-03 22:09:31',1,0,21,11042),(18,'Deposit',0,12000,'2016-04-03 22:16:49',0,0,22,22000),(18,'AMZN',1,599,'2016-04-03 22:17:06',1,0,23,21402),(18,'TSLA',45,238,'2016-04-03 22:17:27',1,0,24,21392),(18,'AMZN',1,599,'2016-04-03 22:18:25',0,1,25,21990),(18,'amzn',3,602,'2016-04-07 01:26:21',1,0,26,21989),(18,'FB',1,114,'2016-04-07 01:31:46',1,0,27,21875),(18,'FB',1,114,'2016-04-07 01:32:13',0,1,28,21989);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (2,11,'APPL',90),(0,11,'BABA',8),(0,11,'FB',35),(0,11,'FREE',12004),(0,11,'SP',1),(0,11,'SPY',2),(0,11,'TSLA',69),(0,18,'AMZN',3),(0,18,'TSLA',45);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10000.0000),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000),(11,'rbookhout','$2y$10$gNCXIMvGcox3UD.7097wEedAAENLwyCczoE3bECcSoB1V2HGpY2R6',11042.0276),(14,'rbookhou','$1$vp6yXGn4$dQ52I.ecl5qaEw8gqfut9/',10000.0000),(15,'rb','$1$1rklvciU$bd8SK82wk58nmqoarGXyM.',10000.0000),(16,'rbookhout1','$1$WEjvaCE.$qOVLgcOknh9eabzTKor70.',10000.0000),(17,'rbookhout12','$1$JNaDu3bL$syBLuOrSnnW7E6/DswiyS1',10000.0000),(18,'rbookhout13','$1$ct1LBKlL$IXiJjmnsM0jb0L0fqjoYv1',21989.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-04-07  1:37:49
