export default [
  {
    path: '/user',
    layout: false,
    routes: [
      {
        path: '/user',
        routes: [
          {
            name: 'login',
            path: '/user/login',
            component: './user/Login',
          },
        ],
      },
      {
        component: './404',
      },
    ],
  },
  {
    path: '/welcome',
    name: 'welcome',
    icon: 'smile',
    component: './Welcome',
  },
  {
    path: '/admin',
    name: 'admin',
    icon: 'crown',
    // access: 'canAdmin',
    component: './Admin',
    routes: [
      {
        path: '/admin/sub-page',
        name: 'sub-page',
        icon: 'smile',
        component: './Welcome',
      },
      {
        component: './404',
      },
    ],
  },
  {
    name: 'list.table-list',
    icon: 'table',
    path: '/list',
    component: './TableList',
  },
  {
    path: '/',
    redirect: '/welcome',
  },
  {
    component: './404',
  },

  {
    path: '/audio',
    // layout: false,
    routes: [
      {
        path: '/audio',
        routes: [
          {
            name: 'play',
            path: '/audio/Play',
            component: './audio/Play',
          },
        ],
      },
      {
        component: './404',
      },
    ],
  },

  {
    path: '/video',
    // layout: false,
    routes: [
      {
        path: '/video',
        routes: [
          {
            name: 'play',
            path: '/video/Play',
            component: './video/Play',
          },
        ],
      },
      {
        component: './404',
      },
    ],
  },

];
