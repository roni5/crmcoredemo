<?php
/**
 * @file
 * crm_core_petition.sample_data.inc
 */

/**
 * Called from the profile installer for sample data creation.
 */
function crm_core_blog_sample_data($count = 10) {
  if (module_exists('devel_generate') && module_exists('crm_core_devel_generate')) {
    module_load_include('inc', 'devel_generate', 'devel_generate');
    module_load_include('inc', 'crm_core_devel_generate', 'devel_generate');

    $devel_config_base = array(
      'time_range' => 31536000,
      'title_length' => 4,
      'users' => devel_get_users(),
    );

    $contact = new stdClass();
    $contact->uid = 1;

    $config = array(
      'devel_generate_content_add_node' => $devel_config_base + array('node_types' => array('blog_post' => 'blog_post')),
    );

    foreach ($config as $function => $settings) {
      if (function_exists($function)) {
        for ($i = 0; $i < $count; $i++) {
          if ($function === 'crm_core_devel_generate_contact_add_activity') {
            $result = $function($settings, $settings['type']);
          }
          else {
            $result = $function($settings);
          }
        }
      }
    }
  }
}
