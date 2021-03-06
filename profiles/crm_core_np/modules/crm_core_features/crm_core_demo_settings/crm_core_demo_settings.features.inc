<?php
/**
 * @file
 * crm_core_demo_settings.features.inc
 */

/**
 * Implements hook_default_crm_core_contact_type().
 */
function crm_core_demo_settings_default_crm_core_contact_type() {
  $items = array();
  $items['household'] = entity_import('crm_core_contact_type', '{
    "type" : "household",
    "label" : null,
    "weight" : 0,
    "name" : "Household",
    "description" : "A collection of individuals generally located at the same residence.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "rdf_mapping" : [  ]
  }');
  $items['individual'] = entity_import('crm_core_contact_type', '{
    "type" : "individual",
    "label" : null,
    "weight" : 0,
    "name" : "Individual",
    "description" : "A single individual.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "rdf_mapping" : [  ]
  }');
  $items['organization'] = entity_import('crm_core_contact_type', '{
    "type" : "organization",
    "label" : null,
    "weight" : 0,
    "name" : "Organization",
    "description" : "A collection of individuals or other organizations that has additional contact data.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "rdf_mapping" : [  ]
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_demo_settings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_core_demo_settings_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function crm_core_demo_settings_homebox() {
  $homeboxes = array();

  $homeboxes['crm_core_dashboard'] = array (
    'regions' => 2,
    'cache' => 1,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_crm_core_donor_widget-average' => 
      array (
        'module' => 'views',
        'delta' => 'crm_core_donor_widget-average',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Donors',
        'weight' => -30,
      ),
      'views_038657316d71d4dab156a71ed24f2b25' => 
      array (
        'module' => 'views',
        'delta' => '038657316d71d4dab156a71ed24f2b25',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Petitions',
        'weight' => -29,
      ),
      'views_cff147d847be508f315012f24c5edc53' => 
      array (
        'module' => 'views',
        'delta' => 'cff147d847be508f315012f24c5edc53',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Donations',
        'weight' => -27,
      ),
      'menu_menu-crm-core-content' => 
      array (
        'module' => 'menu',
        'delta' => 'menu-crm-core-content',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Add New...',
        'weight' => -26,
      ),
      'views_d2b9063a2b28cbc611462754cfae32a3' => 
      array (
        'module' => 'views',
        'delta' => 'd2b9063a2b28cbc611462754cfae32a3',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Recent Activity',
        'weight' => -22,
      ),
      'views_crm_core_blog_widget-comments' => 
      array (
        'module' => 'views',
        'delta' => 'crm_core_blog_widget-comments',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Blog',
        'weight' => -32,
      ),
    ),
    'widths' => 
    array (
      1 => 58,
      2 => 40,
    ),
    'title' => 'CRM Dashboard',
    'path' => 'crm/dashboard/hb',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}

/**
 * Implements hook_image_default_styles().
 */
function crm_core_demo_settings_image_default_styles() {
  $styles = array();

  // Exported image style: contact_main_image.
  $styles['contact_main_image'] = array(
    'name' => 'contact_main_image',
    'effects' => array(
      4 => array(
        'label' => 'Desaturate',
        'help' => 'Desaturate converts an image to grayscale.',
        'effect callback' => 'image_desaturate_effect',
        'dimensions passthrough' => TRUE,
        'module' => 'image',
        'name' => 'image_desaturate',
        'data' => array(),
        'weight' => '-8',
      ),
    ),
  );

  return $styles;
}
