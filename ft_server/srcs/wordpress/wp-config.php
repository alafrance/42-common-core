<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'root' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'E7S)xdeioPAMDLKb?K}((FRCg#DQRSl{hfrL-c/0PZbHK~)R>=/GM,MMx)>%os@+' );
define( 'SECURE_AUTH_KEY',  '}El*cF~W*TDT^/V7>f#t=uc7[R^-`Jm[{OL2z.WDJT>rK5@Gxaoz85|Z5E$_vVT*' );
define( 'LOGGED_IN_KEY',    'C+M *tmpSi.>yHVBc0fuoZu9K9sz9a:dnW{8op ,|zJ%Ao~`2u5}#c>)MmXM`s64' );
define( 'NONCE_KEY',        'ds#*hj79H658&/>.TtNwNM(T!83Qo;kpV4q}kO1nWTaIflR,{fN/em~3-w0:]n>r' );
define( 'AUTH_SALT',        'Zq?LNum}uP4^I1KoWi.LIpg~7nm<LJoUoATfk|z0t7sA[f[./I|rg/X!t!]Y4v6;' );
define( 'SECURE_AUTH_SALT', '/?zsf(=GgRz:$3@^O3[VnzSnr&4=b,Ao5qV3YieK8@M.15!.WklCVe%4AgC!jOS=' );
define( 'LOGGED_IN_SALT',   '-1J7!*zer(F$QzD#R%^m&s-n@W-Q|8kCi>;Y6{Z2DqA_Wko7ghB@I2C}^G*n,5Re' );
define( 'NONCE_SALT',       'Vdx4eJMR}~?pbz^DW=|SHl0Mh_YIS;f|E6bx;*DwnnuT>/k4}}}GxobPCOe{H?BE' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

