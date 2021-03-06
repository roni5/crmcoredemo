<header id="navbar" role="banner" class="navbar navbar-fixed-top navbar-inverse">
  <div class="navbar-inner">
  	<div class="container">
  	  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
  	  <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
  		<span class="icon-bar"></span>
  		<span class="icon-bar"></span>
  		<span class="icon-bar"></span>
  	  </a>
  	  
  		<a class="brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
			  <img src="<?php print base_path() . path_to_theme() . '/images/crmcorelogo.png'; ?>" style="float: left; position: absolute;" alt="<?php print t('Home'); ?>" />
  		</a>
  		<a class="brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">CRM Core Demo</a>
  		
  	  <?php if ($site_name || $site_slogan): ?>
    		<hgroup id="site-name-slogan">
    		  <?php if ($site_name): ?>
    			<h1>
    			  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
    			</h1>
    		  <?php endif; ?>
    		</hgroup>
  	  <?php endif; ?>
  	  
  	  <div class="nav-collapse">
    	  <nav role="navigation">
      		<?php if (isset($primary_nav)): ?>
            <?php print render($primary_nav); ?>
      		<?php endif; ?>
      	  <ul class="nav pull-right">
						<li><a href="<?php print base_path() .  'crm'; ?>">CRM Core Admin</a></li>
      	  </div>
    		</nav>
  	  </div>         
  	</div>
  </div>
</header>

<?php if ($page['marquee']): ?>
  <div class="masthead jumbotron">
    <div class="container">
      <?php print render($page['marquee']); ?>
    </div>
  </div>    
<?php endif; ?>  

<div class="container">

  <header role="banner" id="page-header">
    <?php if ( $site_slogan ): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#header -->

	<div class="row">
	  
    <?php if ($page['sidebar_first']): ?>
      <aside class="span3 hidden-phone" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  
	  
	  <section class="<?php print _bootstrap_content_span($columns); ?>">
	  
	    <?php if ($page['top']): ?>
	      <?php print render($page['top']); ?>
		  <?php endif; ?>
	  
      <?php print $messages; ?>
        
      <?php if(!$is_front):?>
      
        <?php if ($page['highlighted']): ?>
          <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <?php if ($breadcrumb): print $breadcrumb; endif;?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($tabs): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if ($page['help']): ?> 
          <div class="well"><?php print render($page['help']); ?></div>
        <?php endif; ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
      <?php endif; ?>
      
      <?php if ($page['above']): ?>
  	  	<!-- TODO: put this in a container -->
        <?php print render($page['above']); ?>
      <?php endif; ?>  
      
      <?php if(!$is_front):?>
	      <?php print render($page['content']); ?>
      <?php endif; ?>  
      
      <?php if ($page['below']): ?>
      	<div class="row">
  		  	<!-- TODO: put this in a container -->
          <?php print render($page['below']); ?>
      	</div>
      <?php endif; ?>  
      
	  </section>

    <?php if ($page['sidebar_second']): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
  
  <?php if ($page['bottom']): ?>
  	<!-- TODO: put this in a container -->
  	<div class="row">
	    <?php print render($page['bottom']); ?>
    </div>
  <?php endif; ?>  
      
  
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>


	

