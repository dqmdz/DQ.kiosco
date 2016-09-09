/*
SQLyog Ultimate v9.63 
MySQL - 5.6.14 : Database - kiosco
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`kiosco` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `kiosco`;

/*Table structure for table `articulo` */

DROP TABLE IF EXISTS `articulo`;

CREATE TABLE `articulo` (
  `art_id` smallint(2) NOT NULL DEFAULT '0',
  `art_nombre` varchar(50) NOT NULL DEFAULT '',
  `art_precio` decimal(10,2) NOT NULL DEFAULT '0.00',
  PRIMARY KEY (`art_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Table structure for table `cliente` */

DROP TABLE IF EXISTS `cliente`;

CREATE TABLE `cliente` (
  `cli_id` smallint(2) NOT NULL DEFAULT '0',
  `cli_nombre` varchar(50) NOT NULL DEFAULT '',
  PRIMARY KEY (`cli_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Table structure for table `tipo` */

DROP TABLE IF EXISTS `tipo`;

CREATE TABLE `tipo` (
  `tip_id` smallint(2) NOT NULL DEFAULT '0',
  `tip_nombre` varchar(50) NOT NULL,
  PRIMARY KEY (`tip_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Table structure for table `venta` */

DROP TABLE IF EXISTS `venta`;

CREATE TABLE `venta` (
  `ven_id` smallint(2) NOT NULL DEFAULT '0',
  `ven_cli_id` smallint(2) NOT NULL DEFAULT '0',
  `ven_tip_id` smallint(2) NOT NULL DEFAULT '0',
  `ven_importe` decimal(10,2) NOT NULL DEFAULT '0.00',
  PRIMARY KEY (`ven_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Table structure for table `ventadetalle` */

DROP TABLE IF EXISTS `ventadetalle`;

CREATE TABLE `ventadetalle` (
  `vde_ven_id` smallint(2) NOT NULL DEFAULT '0',
  `vde_art_id` smallint(2) NOT NULL DEFAULT '0',
  `vde_cantidad` smallint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`vde_ven_id`,`vde_art_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
